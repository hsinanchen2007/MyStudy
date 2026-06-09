```
#define LEN 1000
void dfs(char **arr, int le, int ri, char* board, char *s, int len, int* level, int fi){
    int i, l,ju = 0, leng = 0;
    int pre = ri;
    if(fi == 3) // 3个点了，进行判断
    {
        l = strlen(s + le);
        board[ri] = '\0';
        sscanf(s + le, "%d", &ju);
        if(ju > 255 || l > 3 || l == 0)
            return ;
        if(l == 2 && ju < 10){ // 01 这种情况的判断
            return ;
        }
        if(l == 3 && ju < 100){ // 001 这种状况的判断
            return ;
        }
        board[ri] = '\0';
        strcat(board, s + le);
        arr[*level] = (char *)malloc(sizeof(char) * (len + 10));
        strcpy(arr[*level], board);
        (*level)++;
        return ;
    }
    for(i = le; i < le + 3 && i < len; i++){//到三位的判断
        board[ri++] = s[i];
        board[ri] = '.';
        sscanf(board + pre, "%d", &ju);//这个是转换的函数，很有用。
        leng = i - le;
        if(ju > 255)//525这种情况的判断
            return ;
        if(leng == 1 && ju < 10) // 01 这种情况的判断，进行剪枝。
            return;
        dfs(arr, i + 1, ri + 1, board, s, len, level, fi + 1);
    }
}
char ** restoreIpAddresses(char * s, int* returnSize){
    char **arr = (char **)malloc(sizeof(char*)*LEN);
    int level = 0, fi = 0, len = strlen(s);
    int le = 0, ri = 0;
    char *S = (char *)malloc(sizeof(char) * (len + 10));
    dfs(arr, le, ri, S, s, len, &level, fi);
    *returnSize = level;
    return arr;
}
```