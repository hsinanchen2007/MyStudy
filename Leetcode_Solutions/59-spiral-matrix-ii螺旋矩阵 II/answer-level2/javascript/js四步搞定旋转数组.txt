### 解题思路
![image.png](https://pic.leetcode-cn.com/f8725c3a71235b49a6659888d6367dcd458f4502829ee61403a45602fc8db4ad-image.png)

思路很简单，分四步：
 - 创建结果数组矩阵
 - 规划填充路径数组（找规律得出：n->(n-1)->(n-1)->.....1->1）：
 - 轮询，方向迭代，根据路径数组元素变化，不断切换方向：四个方向，0上， 1右， 2下，3左
 - 计算填充位置：根据方向，来计算是行变化还是列变化，是+1还是-1
### 代码

```javascript
/**
 * @param {number} n
 * @return {number[][]}
 */
var generateMatrix = function(n) {
    const res = new Array(n).fill('').map(item => ([]));
    let row = 0;
    let col = -1;
    let dir = 0; // 思路1：四个方向，0上， 1右， 2下，3左
    const path = [];
    let i = 0;
    while(++i < n) { // 思路2：创建填充规划路径，4：4-3-3-2-2-1-1， 3: 3-2-2-1-1
        path.push(i, i); // 如果为3： 这里构建了： 1-1-2-2
    }
    // 这里相当于 path.push(n); 得到 1-1-2-2-3
    // pathLength = path.pop();
    let pathLength = n;
    for(let i = 1; i <= n * n; i++) {
        if (dir % 2) { // 根据方向来计算将被被改变的行列号
            row += dir > 1 ? -1 : +1; // 行加1
        } else {
            col += dir > 1 ? -1 : +1; // 列加1
        }
        res[row][col] = i;
        pathLength--;
        if (pathLength === 0) {
            pathLength = path.pop();
            // 消耗一个路径元素，则方向就会变一次
            dir = (dir + 1) % 4; 
        }
    }
    return res;
};
```