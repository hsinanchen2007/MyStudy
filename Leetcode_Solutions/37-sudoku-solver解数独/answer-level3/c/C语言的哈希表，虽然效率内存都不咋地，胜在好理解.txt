### 解题思路
C语言哈希表+回溯

### 代码
```c
struct myhash{
    int key;
    UT_hash_handle hh;
};
struct myhash *row[9] = { NULL };
struct myhash *col[9] = { NULL };
struct myhash *box[9] = { NULL };
int addItem(struct myhash **hash, int value){
    struct myhash *tmp = NULL;
    HASH_FIND_INT(*hash, &value, tmp);
    if(tmp == NULL){
        tmp = (struct myhash *)malloc(sizeof(struct myhash));
        tmp->key = value;
        HASH_ADD_INT(*hash, key, tmp);
        return 1;
    }
    return 0;
}
int findItem(struct myhash **hash, int value){
    struct myhash *tmp = NULL;
    HASH_FIND_INT(*hash, &value, tmp);
    if(tmp == NULL){
        return 1;
    }
    return 0;
}
void delItem(struct myhash **hash, int value){
    struct myhash *tmp = NULL;
    HASH_FIND_INT(*hash, &value, tmp);
    if(tmp != NULL){
        HASH_DEL(*hash, tmp);
        free(tmp);
    }
}
int dfs(char** board, int cnt){
    int i;
    if(cnt == 81){
        return 1;
    }
    int rowcnt = cnt / 9;
    int colcnt = cnt % 9;
    int boxIndex = rowcnt / 3 * 3 + colcnt / 3;
    if(board[rowcnt][colcnt] == '.'){
        for(i = 1; i <= 9; i++){
            if(findItem(&row[rowcnt], i) && findItem(&col[colcnt], i)&&findItem(&box[boxIndex], i)){
                board[rowcnt][colcnt] = i + '0';
                addItem(&row[rowcnt], i);
                addItem(&col[colcnt], i);
                addItem(&box[boxIndex], i);
                if(dfs(board, cnt + 1) == 1){
                    return 1;
                }
                delItem(&row[rowcnt], i);
                delItem(&col[colcnt], i);
                delItem(&box[boxIndex], i);
                board[rowcnt][colcnt] = '.';
            }
        } 
    }
    else{
        if(dfs(board, cnt + 1)){
            return 1;
        }

    }
    return 0;
}
void solveSudoku(char** board, int boardSize, int* boardColSize){
    int i, j;
    for(i = 0; i < 9; i++){
        row[i] = NULL;
        col[i] = NULL;
        box[i] = NULL;
    }
    int boxIndex = 0;
	int value;
    for(i = 0; i < 9; i++){
        for(j = 0; j < 9; j++){
            if(board[i][j] != '.'){
                value = board[i][j] - '0';
                boxIndex = i / 3 * 3 + j / 3;
                addItem(&row[i], value);
                addItem(&col[j], value);
                addItem(&box[boxIndex], value);
            }
        }
    }
    dfs(board, 0);
}

```