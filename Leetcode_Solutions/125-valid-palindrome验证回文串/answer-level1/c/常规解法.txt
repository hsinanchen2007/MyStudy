### 解题思路
先申请一个字符串长度大小的字符数组，然后遍历字符串，遇到小写字母和数字就放到新数组中，遇到大写字母，先转换成对应的小写字母再存放到新数组中，最后对比新数组中头尾是否回文即可。
执行用时 :4 ms, 在所有 C 提交中击败了86.60%的用户
内存消耗 :6 MB, 在所有 C 提交中击败了100.00%的用户

### 代码

```c
bool isPalindrome(char * s)
{
    if(s[0]=='\0') return true;//空字符
    int len=strlen(s);
    int j=0;
    char p[len];//只保留字母和数字的字符数组
    for(int i=0;i<len;i++)
    {
        if((s[i]<='z' && s[i]>='a') || (s[i]<='9' && s[i]>='0'))//小写字母和数字直接存
        p[j++]=s[i];
        else if(s[i]<='Z' && s[i]>='A')//把大写字母存成小写
        p[j++]=s[i]+32;
    }
    for(int i=0;i<j/2;i++)
    {
        if(p[i]!=p[j-i-1]) return false;
    }
    return true;


}
```