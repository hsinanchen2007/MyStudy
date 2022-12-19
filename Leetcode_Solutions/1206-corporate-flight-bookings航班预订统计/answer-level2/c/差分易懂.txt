### 解题思路
看到题目首先想到了暴力破解，但是超时
通过已经思考，想到了差分
理解：
从a到b都增加n的话，只需要就建立一个差分队列P；
P[a] += n；
P[b+1] -= n； 注意：是b+1

![image.png](https://pic.leetcode-cn.com/547f38e3b0ec8c19d799f6f39301c83750f094a95a689eab40c460f5b83868f5-image.png)


### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* corpFlightBookings(int** bookings, int bookingsSize, int* bookingsColSize, int n, int* returnSize)
{
    int *res = NULL;
    res = (int *)malloc(sizeof(int) * (n + 2));
    memset(res, 0, (sizeof(int) * (n + 2)));

    int p[n + 2];    
    memset(p, 0, (sizeof(int) * (n + 2)));
    *returnSize = n;
    for (int i = 0; i < bookingsSize; i++) {
        p[bookings[i][0]] += bookings[i][2];
        p[bookings[i][1] + 1] -= bookings[i][2];
    }
    
    for (int i = 1; i <= n; i++) {
        res[i] = res[i - 1] + p[i];
    }
    return (res + 1);
}
```