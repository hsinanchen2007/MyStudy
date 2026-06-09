### 解题思路
从最底下一行开始，状态转移方程：`DP[i, j] = min(DP[i+1,j], DP[i, j+1]) + Trangle[i, j]`。
DP[i,j] 表示从最底层到达该该点的最短距离。额外空间只需要一维数组即可，用于保存每层的距离。
时间复杂度：O(m*n),空间复杂度：O(n)，其中，m 为三角形的高度，n 为三角形最底层元素的个数。
### 代码

```javascript
/**
 * @param {number[][]} triangle
 * @return {number}
 */
var minimumTotal = function (triangle) {
    // 拷贝最底下一行，不修改 triangle 本身
    let mini = [...triangle[triangle.length - 1]];
    for (let i = triangle.length - 2; i >= 0; i--) {
        for (let j = 0; j < triangle[i].length; j++) {
            mini[j] = triangle[i][j] + Math.min(mini[j], mini[j + 1]);
        }
    }
    return mini[0]
};
```
![搜索框传播样式-标准色版.png](https://pic.leetcode-cn.com/a968ebbac6a8b5be707d9c8b39fc0f4dd24ae5adc1c056d7883a70dff02cf6da-%E6%90%9C%E7%B4%A2%E6%A1%86%E4%BC%A0%E6%92%AD%E6%A0%B7%E5%BC%8F-%E6%A0%87%E5%87%86%E8%89%B2%E7%89%88.png)
