### 解题思路


### 代码

```c
int countCharacters(char ** words, int wordsSize, char * chars){
    int res=0, charcmp[26] = {0};
    for(int i = 0; i < strlen(chars); i++)  charcmp[chars[i]-'a']++;
    for(int i = 0; i < wordsSize; i++){
        int mark = 0, curr[26] = {0};
        for(int j = 0; j < strlen(words[i]); j++){
            curr[words[i][j]-'a']++;
            if(curr[words[i][j]-'a'] > charcmp[words[i][j]-'a']){
                mark = 1; break;
            }
        }
        if(mark==0) res+=strlen(words[i]);
    }
    return res;
}
```