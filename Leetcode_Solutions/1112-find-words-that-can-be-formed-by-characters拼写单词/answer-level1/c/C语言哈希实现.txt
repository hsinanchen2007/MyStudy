### 解题思路
将chars的字符即出现次数记录下来，同理遍历words将每个word的字符及出现字数和chars的比较，如果对应字符出现次数小于等于chars的就记录下来。
### 代码

```c
int countCharacters(char ** words, int wordsSize, char * chars){
    int maxlen=0;
    int charslen=strlen(chars);
    if(charslen==0||wordsSize==0)
        return 0;
    int map[26],word[26];
    memset(map,0,sizeof(map));
    for(int i= 0;i<charslen;i++)
        map[chars[i]-'a']++;
    for(int j=0;j<wordsSize;j++)
    {
        memset(word,0,sizeof(word));
        int k;
        int wordlen=strlen(words[j]);
        if(wordlen>charslen)
            continue;
        for(k=0;k<wordlen;k++)
        {
            if(map[words[j][k]-'a'] < ++word[words[j][k]-'a'])
                break;
        }
        if(k==wordlen)
            maxlen+=wordlen;
    }
    return maxlen;
}
```