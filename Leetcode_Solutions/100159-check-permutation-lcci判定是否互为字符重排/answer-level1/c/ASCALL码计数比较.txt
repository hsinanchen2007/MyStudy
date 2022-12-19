### 解题思路
此处撰写解题思路

### 代码

```c
bool CheckPermutation(char* s1, char* s2)
{
    int i,len,num1=0,num2=0;
    if(strlen(s1)!=strlen(s2))
        return false;
    len=strlen(s1);
    for(i=0;i<len;i++)
    {
        s1[i]=s1[i]-'a';
        s2[i]=s2[i]-'a';
        num1+=s1[i];
        num2+=s2[i];
    }
    if(num1==num2)
        return true;
    else
        return false;
}
```