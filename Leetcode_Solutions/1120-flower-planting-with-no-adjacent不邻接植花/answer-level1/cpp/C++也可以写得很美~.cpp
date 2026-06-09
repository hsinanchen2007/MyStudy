vector<int>color(N,1)：存储颜色；
vector<vector<int>>table(N)：存储路径对应表；
set<int>col_set：存储当前花园可用颜色；
```c++ []
vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
    vector<vector<int>>table(N);
    for (auto x : paths)
        table[max(x[0],x[1])-1].push_back(min(x[0],x[1])-1);
    vector<int>color(N,1);
    for (int i = 1; i < N; i++) {
        set<int>col_set{ 1,2,3,4 };
        for (int j = 0; j < table[i].size(); j++)
            col_set.erase(color[table[i][j]]);
        color[i] = *col_set.begin();
    }
    return color;
}
```

