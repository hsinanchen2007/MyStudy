### 解题思路
+ 1.题目指出只有小写字母，创建大小为26的数组记录每个字母的次数；
+ 2.遍历一次字符串，s对应的字母+1，t的-1，从而使字母抵消；
+ 3.注意：s和t可能长度不一样，提前判断
### 代码

```c
bool isAnagram(char * s, char * t){
    int cnt[26]={};
    int len=strlen(s);
    if(len!=strlen(t))
    {
        return 0;
    }
    for(int i=0;i<len;i++)
    {
        cnt[s[i]-'a']++;
        cnt[t[i]-'a']--;
    }
    for(int i=0;i<26;i++)
    {
        if(cnt[i]!=0)
        return 0;
    }
    return 1;
}
```