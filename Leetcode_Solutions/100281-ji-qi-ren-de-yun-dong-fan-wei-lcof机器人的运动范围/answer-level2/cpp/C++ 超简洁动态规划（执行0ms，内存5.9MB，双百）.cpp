![image.png](https://pic.leetcode-cn.com/9daa862afc46fb24965b3904c5202e5b155934e26e7bcb4c4a5467a1f13997be-image.png)

正如官方题解所述，我们在搜索的过程中搜索方向可以缩减为向右和向下，而不必再向上和向左进行搜索。 （蓝色为非“障碍物”方格）

![image.png](https://pic.leetcode-cn.com/9a2f68718d39a53740a240f5dfc9f25ff47d3b3b99f8118b254d83d57dab420e-image.png)

因此我们可以使用动态规划。

对于`x, y`，判断其各位之和小于等于`k`的代码如下。（`check(x, y, k)`为`true`代表`(x, y)`是蓝色）

```cpp
int check(int x, int y, int k) {
    int sum = 0;
    while (x > 0) {
        sum += x % 10;
        x /= 10;
    }
    while (y > 0) {
        sum += y % 10;
        y /= 10;
    }
    return sum <= k;
}
```

然后，非常简单地，我们检查每一个蓝色的格子是否在左边或上边有一个可以到达的格子。

```cpp
int movingCount(int m, int n, int k) {
    vector<bool> dp(n);
    int result = 0;
    for (int mi = 0; mi < m; mi++) {
        for (int ni = 0; ni < n; ni++) {
            if (dp[ni] = check(mi, ni, k) && ((mi != 0 && dp[ni]) || (ni != 0 && dp[ni - 1])) || (mi == 0 && ni == 0))
                result++;
        }
    }
    return result;
}
```