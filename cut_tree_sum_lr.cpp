// author : kratos0-f
 
// дан массив, мы обрабатываем 2 операции :
// set(i, j); // заменить i элемент массива на j 
// sum (l, r); // посчитать сумму на отрезке от l до r
 
// для этого будем использовать дерево отрезков
 
#include <bits/stdc++.h>
 
using namespace std;
 
const unsigned long long MAXN = 500000;  // максимальный размер массива
 
long long n, t[4*MAXN]; // количество элементов в массиве и сам массив
 
void build (long long a[], unsigned long long v, unsigned long long tl, unsigned long long tr){  // функция, которая строит дерево, на вход : массив, вершина
// текущая, ее границы
	if (tl == tr){ // если у нашей вершины нет детей, то нам ее жалко
		t[v] = a[tl];  // запишем в нее, все, что ей надо
	} else {
		unsigned long long tm = (tl + tr) / 2;  // середина, которая разбивает отрезок, на отрезки для детей
		build (a, v*2, tl, tm); // строим массив для одного ребенка
		build (a, v*2+1, tm+1, tr);  // строи массив для другого ребенка
		t[v] = t[v*2] + t[v*2 + 1];  // записываем сумму детей
	}
}
 
long long sum (unsigned long long v, unsigned long long tl, unsigned long long tr, unsigned long long l, unsigned long long r) { // функция для суммы на отрезке, на вход текущую вершину
// границы этой вершины и границы отрезка
	if (l > r){ // если левый конец отрезка дальше правого, то у отрезка проблемы
		return 0;
	 } else if (l == tl && r == tr) { // если наш отрезок полностью совпал, то вернем сумму в этой вершине
		return t[v];
	}
	unsigned long long tm = (tl + tr) / 2; // иначе, посчитаем границу между детьми
	return sum (v*2, tl, tm, l, min(r,tm)) + sum (v*2+1, tm+1, tr, max(l,tm+1), r); // вернем тот же запрос, только от детей
}
 
 
void update (unsigned long long v, unsigned long long tl, unsigned long long tr, unsigned long long pos, unsigned long long new_val) { // функция для изменения одного значения, на вход текущая вершина
// границы вершины, позиция, которую меняем и на что меняем
	if (tl == tr) { // если у нашей вершины нет детей, то запишем в нее то, что надо 
		t[v] = new_val;
	} else {  // иначе, найдем границу между детьми, обновим в каждом ребенке и в вершину запишем новую сумму
		unsigned long long tm = (tl + tr) / 2;
		if (pos <= tm) {
			update (v*2, tl, tm, pos, new_val);
		} else {
			update (v*2+1, tm+1, tr, pos, new_val);
		}
		t[v] = t[v*2] + t[v*2+1];
	}
}
 
 
int main(){
	cin >> n;
	long long a[n];
 
	for (int i = 0; i < n; i++) cin >> a[i];
 
	build (a, 1, 0, n-1);
 
	string cmd;
	while (cin >> cmd){
		if (cmd == "set"){
			unsigned long long i, x;
			cin >> i >> x;
			update(1, 0, n-1, i-1, x);
		} else if (cmd == "sum"){
			unsigned long long l, r;
			cin >> l >> r;
			cout << sum(1, 0, n-1, l-1, r-1) << "\n";
		}
	}
 
	return 0;
}
