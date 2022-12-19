### 解题思路
关键点在于needle[j] != haystack[i + j]，而不是haystack[i]

### 代码

```c
int strStr(char * haystack, char * needle){


    int M =strlen(haystack) ;
    int N = strlen(needle);

    for (int i = 0; i <= M - N; i++)//对于i<=M-N重点理解
    {
        int j;
        for (j = 0; j < N; j++)
        {
            if (needle[j] != haystack[i + j])
            {
                break;
            }
        }
        if (j == N)
            return i;
    }
    return -1;
}
```