### 解题思路
也是参考了其他代码所写，自己真的是太菜了。
如果words中有chars中的字母，那么words[i]中每个字母出现的次数必定小于chars中出现的次数。
对words中每个单词进行遍历，判断每个单词中每个字母出现的次数是否小于chars中对应字母出现的次数。
如果小于，继续遍历这个单词的下个字母。如果大于，说明不是chars中的单词。可以遍历下一个单词。

### 代码

```c
int countCharacters(char ** words, int wordsSize, char * chars){
    short characters[26] = {0};
    int cnt = 0;
    
    for(int i = 0; i < strlen(chars); i++) 
        characters[chars[i] - 'a']++;
    for(int i = 0; i < wordsSize; i++)
    {
        short cur[26] = {0};
        int mask = 0;
        for(int j = 0; j < strlen(words[i]); j++)
        {
            cur[words[i][j] - 'a']++;
            if(cur[words[i][j] - 'a'] > characters[words[i][j] - 'a'])
            {
                mask = 1;
                break;
            }
            
        }
        if(mask == 0) cnt = cnt + strlen(words[i]);
    }
    return cnt;
}
```