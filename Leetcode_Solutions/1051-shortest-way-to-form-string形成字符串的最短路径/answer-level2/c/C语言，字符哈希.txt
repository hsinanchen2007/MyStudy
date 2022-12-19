### 解题思路
记下target前一个字符在source中的最小可取位置，然后查找当前字符在上一个字符
后边的第一个字符，如果找到，则更新last值，否则就需要新增一个子串，last更新
为当前字符第一次出现的位置

### 代码

```c
int shortestWay(char * source, char * target){
    int ret = 0;
    int cnt1[26] = {0};
    int pos1[26][1000] = {0};
    int cnt2[26] = {0};
    int idx = 0;
    int last = 1001;
    int i = 0;
    int j = 0;
    int k = 0;
    
    for (i = 0; source[i]; i++)
    {
        pos1[source[i]-'a'][cnt1[source[i]-'a']] = i;
        cnt1[source[i]-'a']++;
    }
    
    for (i = 0; target[i]; i++)
    {
        if (0 == cnt1[target[i]-'a'])
        {
            return -1;
        }
        cnt2[target[i]-'a']++;
    }
    
    for (i = 0; target[i]; i++)
    {
        idx = target[i]-'a';
        for (j = cnt1[idx]-1; j >= 0; j--)
        {
            if (pos1[idx][j] <= last)
            {
                break;
            }
        }
        
        if (j == cnt1[idx]-1)
        {
            last = pos1[idx][0];
            ret++;
        }
        else
        {
            last = pos1[idx][j+1];
        }
    }
    
    return ret;
}
```