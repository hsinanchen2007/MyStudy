### 解题思路
我发现用strlen真的耗时间，换成用'\0'的话快多了，又学一招

### 代码

```c
bool isAnagram(char * s, char * t)
{
    //应该是只要构成两个字符串的字母都是一样且排列顺序不同
    //我发现用strlen真的耗时间，换成用'\0'的话快多了，又学一招
    int ss[26]={0},tt[26]={0};
    for(int i=0;s[i]!='\0';i++) ss[s[i]-'a']++;
    for(int i=0;t[i]!='\0';i++) tt[t[i]-'a']++;
    for(int i=0;i<26;i++)
    if(ss[i]!=tt[i]) return false;
    return true;
}
```