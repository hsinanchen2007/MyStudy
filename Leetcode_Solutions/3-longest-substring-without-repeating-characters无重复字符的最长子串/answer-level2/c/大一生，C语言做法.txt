### 解题思路
此处撰写解题思路

### 代码

```c

int lengthOfLongestSubstring(char * s){

int i,j,a,k,m;
a = 0,k=0, m = 0;

for(i = 0;i<strlen(s);i++ )//strlen = 6
    {for(j = 0+m;j <= i;j++)
        {
            if(s[i] == s[j] && i != j)
                {
                    m = m + 1;
                    k = 0;
                    j = m - 1;
                    continue;                }
            else
            k++;

        }
    if(k > a)
        a = k;
    k = 0;
    }



return a;
}
```