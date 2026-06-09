1. O（mn）
```
struct location{//保存值为0的元素的坐标值
    int x;
    int y;
    location(int i, int j): x(i), y(j){}
};
void setZeroes(vector<vector<int>>& matrix) {
    vector<location*> position;
    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < matrix[i].size(); j++){
            if(matrix[i][j] == 0){
                position.push_back(new location(i, j));
            }
        }
    }
    for(auto item : position){
        for(int i = 0; i < matrix.size(); i++){
            matrix[i][item->y] = 0;
        }
        for(int j = 0; j < matrix[item->x].size(); j++){
            matrix[item->x][j] = 0;
        }
    }
}
```

2. O（m+n）
```
void setZeroes(vector<vector<int>>& matrix) {
    unordered_set<int> row;//保存应该置零的行坐标
    unordered_set<int> column;//保存应该置零的列坐标
    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < matrix[i].size(); j++){
            if(matrix[i][j] == 0){
                row.insert(i);
                column.insert(j);
            }
        }
    }
    for(auto item : column){
        for(int i = 0; i < matrix.size(); i++){
            matrix[i][item] = 0;
        }
    }
    for(auto item : row){
        for(int j = 0; j < matrix[item].size(); j++){
            matrix[item][j] = 0;
        }
    }
}
```

3. O（1）

```
void setZeroes(vector<vector<int>>& matrix) {
    bool row = false;//第一行是否需要置零
    bool column = false;//第一列是否需要置零
    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < matrix[i].size(); j++){
            if(matrix[i][j] == 0){
                if( i == 0){
                    row = true;//第一行需要置零
                }
                if(j == 0){
                    column = true;//第一列需要置零
                }
                matrix[i][0] = 0;//第i行第一个元素置零，表示这一行需要全部置零
                matrix[0][j] = 0;//第j列第一个元素置零，表示这一列需要全部置零
            }
        }   
    }
    for(int i = 1; i < matrix.size(); i ++){
        if(matrix[i][0] == 0){//第i行第一个元素为零，表示这一行需要全部置零
            for(int j = 1; j < matrix[i].size(); j++){
                matrix[i][j] = 0;
            }
        }
    }
    for(int j = 1; j < matrix[0].size(); j ++){
        if(matrix[0][j] == 0){//第j列第一个元素为零，表示这一列需要全部置零
            for(int i = 1; i < matrix.size(); i++){
                matrix[i][j] = 0;
            }
        }
    }
    if(row == true){//第一行需要置零
        for(int j = 1; j < matrix[0].size(); j++){
                matrix[0][j] = 0;
        }
    }
    if(column == true){//第一列需要置零
        for(int i = 1; i < matrix.size(); i++){
                matrix[i][0] = 0;
        }
    }
}
```

