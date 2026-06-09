### 解题思路
1.用[i,j]滑动窗口求解,i和j从字符串头部开始，判断[i,j]范围内是否有重复字符，若没有则j后移直到[i.j]范围内有重复字符，更新最大字符长度并从i+1处重新遍历。
2.判断[i,j]范围内是否有重复字符：借助ASCLL码来映射每个字符对应的index，标记出现过的字符。

### 代码

```c
bool Unique(char *s,int i,int j)
{
    int flag[128] = {0};
    int n;
    for(n=i;n<=j;n++)
    {
        if(!flag[*(s+n)])
        {
            flag[*(s+n)] = 1;
        }
        else
        {
            return false;
        }
    }
    return true;
}

int lengthOfLongestSubstring(char * s){
    int i,j;
    int max = 0;
    int len = strlen(s);
    int n = 0;
    for(i=0;i<len;i++)
    {
        for(j=i;j<len;j++)
        {
            if(Unique(s,i,j))
            {
                n++;
            }
            else
            {
                break;
            }
        }
        max = max>n ? max:n;
        n = 0;
    }
    return max;
}
```