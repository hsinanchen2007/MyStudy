### 解题思路
纯C 动态规划 清清爽爽

### 代码

```c
int minCut(char * s){
    int length = strlen(s);
    int left = 0;
    int right = 0;
    bool** ppbVolid = (bool**)malloc(length * sizeof(bool*));
    for (left = 0; left <= length - 1; left++)
    {
        ppbVolid[left] = (bool*)malloc(length * sizeof(bool));
        memset(ppbVolid[left], true, length * sizeof(bool));
    }

    int* pRes = (int*)malloc(length * sizeof(int));
    for (left = 0; left <= length - 1; left++)
    {
        pRes[left] = length;
    }

    for (int step = 1; step <= length - 1; step++)
    {
        for (left = 0, right = left + step; right <= length - 1; left++, right++)
        {
            ppbVolid[left][right] = (s[left] == s[right] && ppbVolid[left + 1][right - 1]);
        }
    }

    for (right = 0; right <= length - 1; right++)
    {
        if (ppbVolid[0][right])
        {
            pRes[right] = 0;
            continue;
        }

        for (left = 0; left <= right; left++)
        {
            if (ppbVolid[left][right])
            {
                pRes[right] = pRes[right] < pRes[left - 1] + 1 ? pRes[right] : pRes[left - 1] + 1;
            }
        }
    }

    return pRes[length - 1];
}

```