### 解题思路
题目中子序列不是子串，字符不需相连。因此只有3种情况：
1.s为空，返回0
2.s本身为回文序列，返回1
3.先删除全部的a，再删除全部的b，返回2

### 代码

```c
int removePalindromeSub(char * s)
{
    int num=0;
    num=strlen(s);
    if(num==0)
        return 0;
    int i=0,flag=1;
    for(i=0;i<num-i;i++)
    {
        if(s[i]!=s[num-i-1])
        {   
            flag=0;
            break;
        }
    }
    if(flag==1)
        return 1;
    else
        return 2;
}
```