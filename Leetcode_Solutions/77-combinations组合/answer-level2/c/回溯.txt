### 解题思路
1、计算个数（**注意：可能超过int长度，需要使用long**）
2、递归回溯
![image.png](https://pic.leetcode-cn.com/78bd02cf23e85155a30e91ac685620930c761132370e7e9b9062a31a751cd09e-image.png)

### 代码

```c
static int *g_hash = NULL;
static int g_resCnt = 0;
static int g_n = 0;
static int g_k = 0;

static bool Init(const int n, const int k)
{
    g_n = n;
    g_k = k;
    g_resCnt = 0;
    if (g_hash != NULL) {
        free(g_hash);
        g_hash = NULL;
    }
    g_hash = (int *)malloc(n * sizeof(int));
    if (g_hash == NULL) {
        return false;
    }
    memset(g_hash, 0, n * sizeof(int));
    return true;
}

static void Release(void)
{
    g_n = 0;
    g_k = 0;
    g_resCnt = 0;
    if (g_hash != NULL) {
        free(g_hash);
        g_hash = NULL;
    }
}

static int CalcRetSize(int n, int k)
{
    long tmp = 1;
    long tmp1 = 1;
    for (int i = 0; i < k; i++)
    {
        tmp *= n - i;
        tmp1 *= i + 1;
    }
    return (int)(tmp / tmp1 + 1);
}

static int **MallocRes(int n, int k) {
    int **res = NULL;
    res = (int **)malloc(sizeof(int *) * n);
    if (res == NULL) {
        return NULL;
    }

    for (int i = 0; i < n; i++) {
        res[i] = (int *)malloc(k * sizeof(int));
        if (res[i] == NULL) {
            for (int j = 0; j < i; j++) {
                free(res[j]);
                res[j] = NULL;
            }
            free(res);
            res = NULL;
            return NULL;
        }
        memset(res[i], 0, (k * sizeof(int)));
    }
    return res;
}

static void GetRetColSizes(int n, int k, int** returnColumnSizes)
{
    *returnColumnSizes = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        (*returnColumnSizes)[i] = k;
    }
    return;
}

static void GetRes(int **res, int cnt, int start, int *tmp)
{
    if (cnt == g_k) {
        for (int i = 0; i < g_k; i++) {
            res[g_resCnt][i] = tmp[i];
        }
        g_resCnt++;
        return;
    }    
    
    for (int i = start + 1; i <= g_n; i++) {
        if (g_hash[i - 1] != 0) {
            continue;
        }
        g_hash[i - 1] = 1;
        tmp[cnt] = i;
        GetRes(res, cnt + 1, i, tmp);
        g_hash[i - 1] = 0;
    }
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** combine(int n, int k, int* returnSize, int** returnColumnSizes)
{
    *returnSize = 0;
    int retSize = CalcRetSize(n, k);
    printf("resSize = %d\n", retSize);
    if (retSize == 0) {
        return NULL;
    }

    if (!Init(n, k)) {
        return NULL;
    }

    int **res = NULL;
    res = MallocRes(retSize, k);
    if (res == NULL) {
        return NULL;
    }
    int tmp[k];
    memset(tmp, 0, k * sizeof(int));
    GetRes(res, 0, 0, tmp);
    *returnSize = g_resCnt;
    GetRetColSizes(retSize, k, returnColumnSizes);
    Release();
    return res;
}
```