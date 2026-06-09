### 解题思路
strstr()

### 代码

```c
char * boldWords(char ** words, int wordsSize, char * S)
{
    int flag[500] = {0};
    int i;
    char *temp = NULL;
    int len = strlen(S);
    int tempLen = 0;
    char *res = (char *)calloc(4 * len, sizeof(char));
    int index = 0;

    for (i = 0; i < wordsSize; i++) {
        temp = strstr(S,words[i]);
        tempLen = strlen(words[i]);
        while (temp != NULL) {
            int start = (temp - S) / sizeof(char);
            for (int j = start; j < (tempLen + start); j++) {
                flag[j] = 1;
            }
            temp = strstr(temp + 1, words[i]);
        }
    }

    for (i = 0; i < len; i++) {
        if (((i > 0 ) &&  (flag[i - 1] == 0) && (flag[i] == 1)) || (i == 0 && flag[i] == 1) ) {
            res[index++] = '<';
            res[index++] = 'b';
            res[index++] = '>';           
        } 
        res[index++] = S[i];   
        if ((i + 1 < len && flag[i+1] == 0 && flag[i] == 1) || (flag[i] == 1 && i == len -1)) {    
            res[index++] = '<';
            res[index++] = '/';
            res[index++] = 'b';
            res[index++] = '>';            
        } 
    }
    return res;
}
```