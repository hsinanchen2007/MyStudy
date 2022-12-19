### 解题思路
先将大写字母全转变为小写字母，然后双指针，一个从前到后，另一个从后到前
时间复杂度为（N^2） 空间复杂的为（1）
有很大优化空间；
### 代码

```c
bool isPalindrome(char * s)
{
    int i=0;
    int len=strlen(s);
    int j=len-1;
    int count;
    
    for(count=0;count<len;count++)
    {
        if(s[count]<='Z' && s[count]>='A')
        {
            s[count]+='a'-'A';
        }
    }
    
    
    for(;i<len;i++)
    {
        if((s[i]>='a' && s[i]=<'z') || (s[i]>='0' && s[i]=<'9'))
        {
            while(j>-1)
            {
                if((s[j]>='a' && s[j]=<'z') || (s[j]>='0' && s[j]=<'9'))
                {
                    
                    if(s[i]==s[j])
                    {
                        j--;
                        break;
                    }else
                    {
                        return false;
                    }
                }else
                {
                    j--;
                }
            }
        }
    }
    return true;
}
```