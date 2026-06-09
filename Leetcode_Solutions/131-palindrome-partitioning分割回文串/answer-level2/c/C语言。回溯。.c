```
/**
 * 先构造dp二维数组,dp[i][j]用于快速判断s[i]到s[j]是不是回文字符串。
 * 从0开始遍历字符串s，假设s[0]到s[i]为回文字符串，则记录位置i，然后递归判断剩下剩余的字符串。
 * 当递归到'\0'时，说明找到一组回文字符串, 根据位置i的数据进行保存。
 */
bool** initDp(char* s, int size){
    int i, j;
    bool** dp = (bool**)malloc(sizeof(bool*) * size);
    for(i = 0; i < size; i++){
        dp[i] = (bool*)malloc(sizeof(bool) * size);
        memset(dp[i], 0, sizeof(bool) * size);
    }

    for(j = 0; j < size; j++){
        dp[j][j] = true;
        for(i = j - 1; i >= 0; i--){
            if(s[i] == s[j] && (i == j - 1 || dp[i+1][j-1] == true)){
                dp[i][j] = true;
            }
        }
    }

    return dp;
}


void _partition(char* s, int pos, int* buf, int bufSize, bool** dp, char*** res, int* returnSize, int** returnColumnSizes){
    if(s[pos] == '\0'){
        res[*returnSize] = (char**)malloc(sizeof(char*) * (bufSize-1));
        (*returnColumnSizes)[*returnSize] = bufSize - 1;
        for(int j = 1; j < bufSize; j++){
            char* str = (char*)malloc(sizeof(char) * (buf[j] - buf[j-1] + 1));
            int l = 0;
            for(int k = buf[j-1] + 1; k <= buf[j]; k++){
                str[l++] = s[k];
            }
            str[l] = '\0';
            res[*returnSize][j-1] = str;
        }
        (*returnSize)++;
        return ;
    }

    for(int i = pos; s[i] != '\0'; i++){
        if(dp[pos][i]){
            buf[bufSize] = i;
            _partition(s, i+1, buf, bufSize + 1, dp, res, returnSize, returnColumnSizes);
        }
    }
}


char*** partition(char* s, int* returnSize, int** returnColumnSizes){
    int size = strlen(s);
    char*** res = (char***)malloc(sizeof(char**) * 1024);
    (*returnColumnSizes) = (int*)malloc(sizeof(int) * 1024);
    *returnSize = 0;
    int* buf = (int*)malloc(sizeof(int) * (size+1));
    buf[0] = -1;
    bool** dp = initDp(s, size);
    
    _partition(s, 0, buf, 1, dp, res, returnSize, returnColumnSizes);
    
    return res;
}
```
