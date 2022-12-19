### 解题思路
* 先排除特殊情况 两个都为空、一个为空、两个字符串长度不等
* 利用两个数组统计两个字符串每个字符出现的次数
* 最后比较两个数组中的每个值是否相等

### 代码

```c
bool isAnagram(char * s, char * t){
    if(s==NULL&&t==NULL)
      return true;
    if(s==NULL&&t!=NULL)
      return false;
    if(s!=NULL&&t==NULL)
      return false;
    if(strlen(s)!=strlen(t))
      return false;
    int  strNumberOfs[26]={};
    int  strNumberOft[26]={};

    for(int i=0;i<26;i++)
    {
        strNumberOfs[i]=0;
        strNumberOft[i]=0;
    }
    for(int i=0;i<strlen(t);i++)
    {
        strNumberOfs[(s[i]-'a')]++;
        strNumberOft[(t[i]-'a')]++;
    }
    for(int i=0;i<26;i++)
    {
        if(strNumberOfs[i]!=strNumberOft[i])
           return false;
    }
    return true;

}
```