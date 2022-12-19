### 解题思路
此题主要捋清思路
底部面积：先求出0的个数，然后用矩阵元素个数减去0的个数
左侧面积：每个数组grid[i]中数值最大值的和
前侧面积：稍复杂一些，每个数组grid中相同列数最大值的和

一开始傻傻的用数组排序来求最大值，忘记数组有一个Math.max()功能，果不其然，效率低下，经过修改过后，性能显著提高
![11111.png](https://pic.leetcode-cn.com/7f434236e0f9150a25279b8de4926e24b2bd4fa4e3f785273ab83f80e2493605-11111.png)



### 代码

```javascript
/**
 * @param {number[][]} grid
 * @return {number}
 */
var projectionArea = function(grid) {
    let n = grid.length,
        squares = n * n,
        area = 0,
        num0s = 0
    for(let i=0;i<n;i++){
        let tempY = 0
            tempZ = 0
        for(let j=0;j<n;j++){
            tempY = Math.max(tempY,grid[i][j])
            tempZ = Math.max(tempZ,grid[j][i])
            if(!grid[i][j]){
                num0s++
            }
        }
        area += tempY
        area += tempZ
    }
    return area + squares - num0s
};
```