思路：用hash数组存放每个大写字母的行号，如Q在第1行，然后遍历每个单词，行号不一致则遍历下一个单词，否则赋予结果数组。
```
char ** findWords(char ** words, int wordsSize, int* returnSize){
    *returnSize = 0;
    if(words == NULL || wordsSize == 0){
        return NULL;
    }
    // 26个大写字母对应的行号，如Q在第1行
    //             A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z
    int hash[26]= {2, 3, 3, 2, 1, 2, 2, 2, 1, 2, 2, 2, 3, 3, 1, 1, 1, 1, 2, 1, 1, 3, 1, 3, 1, 3};
    char **result = (char **)calloc(wordsSize, sizeof(char *));
    int i, j, len;
    int num = 0;//字符所在行号

    for(i = 0; i < wordsSize; i++){
        len = strlen(words[i]);
        if(len == 0) continue;
        num = hash[toupper(words[i][0]) - 'A']; //第一个字符的行号
        for(j = 1; j < len; j++){
            if(num != hash[toupper(words[i][j]) - 'A']){
                break;
            }
        }
        if(j == len){//单词所有字符在一行
            result[(*returnSize)++] = words[i];
        }
    }
    return result;
}

```
