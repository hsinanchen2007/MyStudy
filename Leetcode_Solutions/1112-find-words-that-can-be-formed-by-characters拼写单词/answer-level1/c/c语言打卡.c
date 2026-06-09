### 解题思路
此处撰写解题思路

### 代码

```c
int countCharacters(char ** words, int wordsSize, char * chars){
    int i, j, num, f, *hashc = (int*)calloc(26, sizeof(int)), *hashw = (int*)calloc(26, sizeof(int)), *flag = (int*)calloc(26, sizeof(int));
    for(i = 0;i < strlen(chars);hashc[chars[i] - 'a'] ++, i ++);
    for(i = 0, num = 0;i < wordsSize;i ++){
        memset(hashw, 0, 26 * sizeof(int));
        memset(flag, 0, 26 * sizeof(int));
        f = 1;
        for(j = 0;j < strlen(words[i]);j ++)
            if(hashc[words[i][j] - 'a'] != 0)
                if(hashw[words[i][j] - 'a'] != 0)
                    hashw[words[i][j] - 'a'] --;
                else if(flag[words[i][j] - 'a'] == 0){
                    hashw[words[i][j] - 'a'] = hashc[words[i][j] - 'a'] - 1;
                    flag[words[i][j] - 'a'] = 1;
                }
                else{
                    f = 0;
                    break;
                }
            else{
                f = 0;
                break;
            }
        num = (f == 1 ? num + strlen(words[i]) : num);
    }
    return num;
}
```