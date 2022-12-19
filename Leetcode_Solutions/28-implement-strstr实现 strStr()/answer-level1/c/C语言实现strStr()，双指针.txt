### 解题思路
从最后一个字符开始依次向前比对，直至满足要求。有一些边界条件需要注意一下。
初学者，写的有些啰嗦。

### 代码

```c
int strStr(char *haystack, char *needle)
{
    int n_len = strlen(needle);
    if (n_len == 0)
    {
        return 0;
    }
    if (strlen(haystack) < n_len)
    {
        return -1;
    }
    int i = n_len - 1, j;
    int first_occ = -1, occ;

    while (haystack[i] != '\0')
    {
        if (needle[n_len - 1] != haystack[i])
        {
            i++;
        }
        else
        {
            for (j = n_len - 1; j > -1; j--)
            {
                occ = 1;
                if (needle[j] != haystack[i - n_len + 1 + j])
                {
                    occ = 0;
                    i++;
                    break;
                }
            }
            if (occ == 1)
            {
                first_occ = i - n_len + 1;
                break;
            }
        }
    }
    return first_occ;
}
```