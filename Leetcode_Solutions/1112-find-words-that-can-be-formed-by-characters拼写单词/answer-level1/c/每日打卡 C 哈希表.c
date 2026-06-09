### 解题思路
将可以利用的字符串映射到哈希表记数，遍历每一个单词查看是否可以拼成。

### 代码

```c
int countCharacters(char ** words, int wordsSize, char * chars)
{
    int count = 0;
    int hash_char[26]={0},temp[26];   //26个字母
    int len_chars = strlen(chars);      //初始化哈希表
    for(int i=0; i<len_chars; i++)      
    {
        hash_char[chars[i]-'a']++;
    }

    for(int i=0; i<wordsSize; i++)          //遍历每个单词
    {   
        for(int i=0; i<26; i++)      //初始化哈希表
        {
            temp[i]=hash_char[i];
        }

        int len_word=strlen(words[i]);    //遍历单个单词  
        for(int j=0; j<len_word ;j++)
        {       
            temp[words[i][j]-'a']-=1;    //哈希表记数减1
            if(temp[words[i][j]-'a']<0) {count-=len_word;break;} //表中的单词不够拼写
        }

        count+=len_word;
    }

    return count;
}
```