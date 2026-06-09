### 解题思路
1、记录起始站、和终点站的座位数；
2、计算前缀和
3、判断空座是否小于前缀和
![image.png](https://pic.leetcode-cn.com/a384bedfbfcf7354401df4dfc98e861429d86e9f24d456e0f918f69169728118-image.png)


### 代码

```c
bool carPooling(int** trips, int tripsSize, int* tripsColSize, int capacity)
{
    int ans[1001] = {0};
    for (int i = 0; i < tripsSize; i++) {
        ans[trips[i][1]] += trips[i][0];
        ans[trips[i][2]] -= trips[i][0];
    }
    int preSum[1001] = {0};
    for (int i = 1; i < 1001; i++) {
        preSum[i] = preSum[i - 1] + ans[i];
    }

    for (int i = 0; i < 1001; i++) {
        if (preSum[i] > capacity) {
            return false;
        }
    }
    return true;
}
```