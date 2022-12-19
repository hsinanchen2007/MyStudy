### 解题思路
此处撰写解题思路

### 代码

```c
int lengthOfLongestSubstring(char * s){
    int n=strlen(s)-1;
    int i,j,max,t,k=1,x=1;
    if(n!=-1)
    {max=1;
    for(i=0;i<=n;i++)
    {
       for(j=i+1;j<=n;j++)
        {   t=1;
            for(k=i;k<j;k++)
            {
                if(s[k]!=s[j])
                {t++;}
                else break;
            }
            if(t!=j-i+1)
            break;
             if(t>x)
             x=t;
        }
        if(x>max)
        max=x;
    }
     }
     else max=0;
    return max;
}
```