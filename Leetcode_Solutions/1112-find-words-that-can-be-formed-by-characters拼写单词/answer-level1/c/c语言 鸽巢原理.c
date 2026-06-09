### 解题思路
分别记录字符串和单词表中每个单词的每个字母出现的个数，前者出现次数大于等于后者的，即匹配，否则，不够匹配

### 代码

```c
//，记录每个字符出现的个数 
int str_str(const char* s1,const char* s2)
{
    char tmp1[26]={0};
    char tmp2[26]={0};
    for(int i=0;i<strlen(s1);i++)
    {
        tmp1[s1[i]-'a']++;
    }
    for(int j=0;j<strlen(s2);j++)
    {
        tmp2[s2[j]-'a']++;
    }
    for(int k=0;k<26;k++)
    {
        if(tmp1[k]>tmp2[k])  //相同的每个字符 ，字符串个数不够单词表的，就不够拼写
            return -1;
    }
    return 1;
}
int countCharacters(char ** words, int wordsSize, char * chars){
    int ret=0;
    for(int i=0;i<wordsSize;i++)
    {
        if(str_str(words[i],chars)==1)  //满足条件的
            ret+=strlen(words[i]);
    }
    return ret;

}
```