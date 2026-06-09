### 解题思路
动态规划：

和前一个颜色相同，此时说明前一个的栅栏的颜色应与更前面一个栅栏的颜色不同，更前一个栅栏的涂色方法有 F(n - 2) 种，前一个栅栏的涂色方式有 (k - 1) 种，所以此时情况应为 F(n - 2) * (k - 1)
和前一个颜色不同，前一个栅栏的涂色方法有 F(n - 1) 种，当前栅栏的涂色方式有 (k - 1) 种，此时情况应为 F(n - 1) * (k - 1)
所以递推公式应为 F(n) = F(n - 2) * (k - 1) + F(n - 1) * (k - 1)

### 代码

```javascript
/**
 * @param {number} n
 * @param {number} k
 * @return {number}
 */
var numWays = function(n, k) {
    let arr = new Array();
    arr[0] = 0;
    arr[1] = k;
    arr[2] = k * k;
    for(let i = 3; i < n + 1; i++) {
        arr[i] = (k-1) * arr[i-1] + (k-1) * arr[i-2];
    } 
    return arr[n];
};
```