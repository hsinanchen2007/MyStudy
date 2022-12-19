### 解题思路
动态规划，存在性问题，清清爽爽

### 代码

```c
bool canJump(int* nums, int numsSize){
    /*
     * 状态转移: f[j] = OR(0 <= i < j){f[i] AND i + a[i] >= j}
     * 初始条件：f[0] = true
     * 边界情况：无
     */

    bool* pIsCan = (bool*)malloc(sizeof(bool) * numsSize);
    int cur = 0;
    int pre = 0;
    pIsCan[0] = true;

    for (cur = 1; cur <= numsSize - 1; cur++)
    {
        pIsCan[cur] = false;

        for (pre = 0; pre < cur; pre++)
        {
            if (pIsCan[pre] && (pre + nums[pre] >= cur))
            {
                pIsCan[cur] = true;
                break;
            }
        }
    }

    return pIsCan[numsSize - 1];
}
```