#

### 代码

```cpp
class Solution {
public:
int strStr(string haystack, string needle)
{
    int i = 0,j = 0;//扫描主串辅串的指针
    int k = i;//k用来保存扫描主串时回溯的位子
    while(haystack[i] && needle[j])
    {
        if(haystack[i] == needle[j])
        {
            ++i;
            ++j;
        }
        else//若匹配失败，主串回溯到上次臊面开始的位子（k+1）,辅串从头开始扫描
        {
            i = ++k;
            j = 0;
        }
    }
    if(!needle[j])//若匹配成功，辅串一定扫描结束
        return k;
    return -1;
}
};
```