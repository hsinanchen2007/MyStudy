### 解题思路
BFS，每次将队列头出队，搜索该点的右侧点和下侧点，如果合法的话将可以达到的点入队，并将可以达到的点置为已访问。

### 代码

```javascript
/**
 * @param {number} m
 * @param {number} n
 * @param {number} k
 * @return {number}
 */
const isCordValid = (x, y, k, m, n) => {
    const [x1, x2, x3] = [Math.floor(x/100), Math.floor((x%100)/10), x%10];
    const [y1, y2, y3] = [Math.floor(y/100), Math.floor((y%100)/10), y%10];
    return x1+x2+x3+y1+y2+y3 <= k && x > -1 && x < m &&  y > -1 && y < n;
}

var movingCount = function(m, n, k) {
    const matrix = [], queue = [];
    let result = 1;
    for (let i = 0; i < m; ++i) {
        const temp = [];
        for (let j = 0; j < n; ++j) {
            temp.push(false);
        }
        matrix.push(temp);
    }
    queue.push({x: 0, y: 0});
    while (queue.length) {
        const {x, y} = queue.shift();
        if (isCordValid(x+1, y, k, m, n) && !matrix[x+1][y]) {
            matrix[x+1][y] =  true;
            queue.push({x: x+1, y: y});
            ++result;
        }
        if (isCordValid(x, y+1, k, m, n) && !matrix[x][y+1]) {
            matrix[x][y+1] =  true;
            queue.push({x: x, y: y+1});
            ++result;
        }
    }
    return result;
};
```

### 复杂度
- 时间复杂度 O(MN)
- 空间复杂度 O(MN)