### 解题思路
此处撰写解题思路
1、计算s[i]与t[i]的差值绝对值，构造一个新的int数组
2、滑窗来判断满足条件的最大连续子串长度

![image.png](https://pic.leetcode-cn.com/944149b8ab59881127695fce5c8e9519628cd433a2ca1c489c6ae4ac9e1376d9-image.png)

### 代码

```c
static int *g_nums = NULL;
static bool InitNums(int n)
{
    if (g_nums != NULL) {
        free(g_nums);
        g_nums = NULL;
    }

    g_nums = (int *)malloc(sizeof(int) * n);
    if (g_nums == NULL) {
        return false;
    }
    memset(g_nums, 0, sizeof(int) * n);
    return true;
}

static void FreeNums(void)
{
    if (g_nums != NULL) {
        free(g_nums);
        g_nums = NULL;
    }
}

static void SetNums(char *s, char *t, int n)
{
    for (int i = 0; i < n; i++) {
        g_nums[i] = abs(s[i] - t[i]);
        printf ("%d ", g_nums[i]);
    }
    printf("\n");
}

static int GetMax(int n, int maxCost)
{
    int res = 0;
    int sum = 0;
    int left = 0;
    int right = 0;
    while (right < n) {
        sum += g_nums[right];
        right++;
        if (sum <= maxCost) {
            res = fmax(res, (right - left));
            continue;
        }
        while (sum > maxCost) {
            sum -= g_nums[left];
            left++;
        }
    }
    return res;
}

int equalSubstring(char *s, char *t, int maxCost)
{
    int n = strlen(s);
    int res = 0;
    InitNums(n);
    SetNums(s, t, n);
    res = GetMax(n, maxCost);
    FreeNums();
    return res;
}
```