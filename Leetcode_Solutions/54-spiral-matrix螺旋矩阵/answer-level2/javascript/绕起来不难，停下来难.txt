### 解题思路
![image.png](https://pic.leetcode-cn.com/b29d1d4d7c1d544ac7c41fd74f59cf07032bd3a55f86b6648567b208db99b4e3-image.png)

“中止循环”的条件想了一会，不高兴想了，直接判断总数量然后break，代码看上去啰嗦所以速度也不快。

### 代码

```javascript
/**
 * @param {number[][]} matrix
 * @return {number[]}
 */
var spiralOrder = function(matrix) {
    if (matrix.length === 0) return [];

    let h = matrix.length;
    let w = matrix[0].length;
    const qty = h * w;
    let a = 0;
    let arr = [];

    while (true) {
        for (let i = a; i < w - a; i++) {
            arr.push(matrix[a][i]);
        }
        if (arr.length === qty) break;
        for (let i = a + 1; i < h - a; i++) {
            arr.push(matrix[i][w - a - 1]);
        }
        if (arr.length === qty) break;
        for (let i = w - 2 - a; i >= a; i--) {
            arr.push(matrix[h - a - 1][i]);
        }
        if (arr.length === qty) break;
        for (let i = h - 2 - a; i >= a + 1; i--) {
            arr.push(matrix[i][a]);
        }
        if (arr.length === qty) break;
        a++;
    }
    return arr;
};
```