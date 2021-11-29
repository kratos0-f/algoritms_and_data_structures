# Лекция 1: Графы, dfs и bfs (13 октября)

кружок олимп. программирования ИТМО, группа B.dist, преп. Хлытин Григорий

## План занятия:

* Что такое **_графы_**?
* Какие бывают _графы_?
    + Ориентированные / неориентированные
    + Связные / несвязные
    + Полные / разреженные
    + Двудольные / недвудольные
    + Деревья / с циклами
* Что такое **_путь_** / **_цикл_** между вершинами **_u_** и **_v_** в графе?
* Что такое **_асимптотика_**, нотация **_О-большое_**
    + _O-большое_ - оценка сверху на время работы, примеры:
        * время работы **_t(n) = n_** это **_O(n)_**, а также **_O(n^2)_**, **_O(n^3)_** и так далее
        * время работы **_t(n) = 5n_** это **_O(n)_**, так как нотация _О-большое_ оценивает с точностью до константы
        * время работы **_t(n) = n^2 + n + 7_** это **_O(n^2)_**, так как нам важен только **_старший_** член
          многочлена (с наибольшей степенью), так как при росте размера входных данных **_n_** он растет быстрее всего
    + Количество вершин в графе **_N_** = **_|V|_** (**_V_** - множество всех вершин, **_|V|_** - размер этого
      множества)
    + Количество ребер в графе **_M_** = **_|E|_** (**_E_** = множество всех ребер, **_|E|_** - размер этого множества)
* Как хранить графы?
    + Матрица смежности (**_O(N^2)_** памяти)
        * занимает очень много памяти, но проста в использовании
        * подходит для полных графов
    + Список ребер (**_O(M)_** памяти)
        * можно хранить отсортированным, тогда поиск ребер из нужной вершины за **_O(log(M))_** времени (с помощью
          бинпоиска)
        * обычно дан во входном файле `input.txt`
        * занимает мало памяти, но неудобен
        * подходит для разреженных графов
    + Список смежности
        * оптимальный вариант хранения графа
        * подходит для любых графов
        * поиск ребер из нужной вершины за **_O(1)_**
        * прост в реализации при помощи `std::vector<std::vector<int>>` в C++
* Что такое обход графа, **_dfs_** и **_bfs_**
    + реализация на C++
    + оценка времени работы **_O(N + M)_**
* Поиск цикла в неориентированном графе при помощи **_dfs_**
    + реализацию на C++ можно
      найти [тут](https://github.com/grifguitar/itmo-circle-B.dist/tree/main/lecture1_graphs_dfs/CycleSearch.h)

#### Запись лекции на _youtube_:

* [Графы, часть первая](https://youtu.be/ECK3XRjtfYQ)
* [Графы, часть вторая](https://youtu.be/Yh0aTFMm5aA)