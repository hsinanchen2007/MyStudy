![Snipaste_2020-04-02_17-00-31.png](https://pic.leetcode-cn.com/d1054abe443be3aba445204ea8c6e9c8b4da695e2bb49f093152516e7c478444-Snipaste_2020-04-02_17-00-31.png)


### 解题思路
方法一：记忆化解法，类似于爬楼梯的方法。
方法二：动态规划

### 代码

```javascript
var cuttingRope = function (n) {
    // 记忆化：哈希表存储计算结果，避免重复计算，预先放入 n = 2 和 3 的结果
    let hashMap = new Map([[2, 1], [3, 2]])
    const recordN = (n) => {
        // 已有结果直接返回结果
        if (hashMap.has(n)) {
            return hashMap.get(n);
        } else {
            let res = -1;
            // 长度为 n 剪一刀，接下来可以选择继续剪或不剪
            // 剪一刀长度为 i 时，此时最大值为 Max(i * (n - i), i * recordN(n - i))
            // recordN(n) 记录的是长度为 n 时的所有情况，所以需要使用 res 累计比较
            for (let i = 1; i < n; i++) {
                res = Math.max(res, i * (n - i), i * recordN(n - i));
            }
            hashMap.set(n, res);
            return res
        }
    }
    return recordN(n)
};
```
方法二：动态规划
```javascript
var cuttingRope = function (n) {
    // dp 对应绳子为 n 的最优解，dp[0] 无意义
    let dp = new Array(n + 1).fill(1);
    // 自底向上递推
    for (let i = 3; i <= n; i++) {
        for (let j = 1; j < i; j++) {
            dp[i] = Math.max(dp[i], j * (i - j), j * dp[i - j]);
        }
    }
    return dp[n]
};
```
![扫码_搜索联合传播样式-标准色版.png](https://pic.leetcode-cn.com/1343cc8fab0af3f6e274fa658b654030dbd4633c2b28a0c44819c4bbc9f31948-%E6%89%AB%E7%A0%81_%E6%90%9C%E7%B4%A2%E8%81%94%E5%90%88%E4%BC%A0%E6%92%AD%E6%A0%B7%E5%BC%8F-%E6%A0%87%E5%87%86%E8%89%B2%E7%89%88.png)
