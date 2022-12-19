```
char ** findAndReplacePattern(char ** words, int wordsSize, char * pattern, int* returnSize){
    int i, b, level = 0;
    char w[26];
    char p[26];
    char **arr = (char **)malloc(sizeof(char *) * 51);
    memset(p, 0, sizeof(char) * 26);
    memset(w, 0, sizeof(char) * 26);
    for(i = 0; i < wordsSize; i++)
    {
        for(b = 0; pattern[b] != '\0'; b++)
        {
            if(p[pattern[b] - 'a'] == 0 && w[words[i][b] - 'a'] == 0)
            {
                p[pattern[b] - 'a'] = words[i][b];
                w[words[i][b]- 'a'] = pattern[b];
            }
            else if((p[pattern[b] - 'a'] != 0 && w[words[i][b] - 'a'] == 0) || (p[pattern[b] - 'a'] == 0 && w[words[i][b] - 'a'] != 0))
                break;
            else if(p[pattern[b] - 'a'] != words[i][b] && w[words[i][b] - 'a'] != pattern[b])
                break;
        }
        if(pattern[b] == '\0')
        {
            arr[level] = (char *)malloc(sizeof(char) * (b + 3));
            strcpy(arr[level++], words[i]);
        }
        memset(p, 0, sizeof(char) * 26);
        memset(w, 0, sizeof(char) * 26);
    }
    *returnSize = level;
    return arr;
}
```
