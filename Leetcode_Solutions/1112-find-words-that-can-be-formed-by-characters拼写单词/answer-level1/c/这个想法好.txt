### 解题思路
此处撰写解题思路

### 代码

```c
int countCharacters(char ** words, int wordsSize, char * chars){
    int res=0, charcmp[26] = {0};
    for(int i = 0; i < strlen(chars); i++)  charcmp[chars[i]-'a']++;  //统计char中哥哥单词的数量，构建b哈希表
    for(int i = 0; i < wordsSize; i++)
    {
        int mark = 0, curr[26] = {0};
        for(int j = 0; j < strlen(words[i]); j++)
        {
            curr[words[i][j]-'a']++;       //统计word的数目
            if(curr[words[i][j]-'a'] > charcmp[words[i][j]-'a'])
            {
                mark = 1; break;
            }
        }
        if(mark==0) res+=strlen(words[i]);
    }
    return res;
}
```