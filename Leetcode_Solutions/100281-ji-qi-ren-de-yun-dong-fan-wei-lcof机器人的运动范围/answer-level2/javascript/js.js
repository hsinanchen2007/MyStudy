### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number} m
 * @param {number} n
 * @param {number} k
 * @return {number}
 */
var movingCount = function (m, n, k) {
    //bfs
    let res = 0;
    if (!m || !n) return 0;
    //判重数组
    let arr = [m];
    for (let i = 0; i < m; i++) {
        arr[i] = new Array(n).fill(false);
    }
    let dx = [-1, 0, 1, 0];
    let dy = [0, 1, 0, -1];
    //路径
    let path = [{
        first: 0,
        second: 0
    }];
    while (path.length) {
        let t = path.pop();
        if (get_sum(t.first, t.second) > k || arr[t.first][t.second]) continue;
        res++;
        arr[t.first][t.second] = true;
        for (let i = 0; i < 4; i++) {
            let x = t.first + dx[i];
            let y = t.second + dy[i];
            if (x < m && x >= 0 && y < n && y >= 0) {
                path.push({ first: x, second: y });
            }
        }
    }
    return res;
};

const get_single_sum = (x) => {
    let s = 0;
    while (x) {
        s += x % 10;
        //要转为整数，js弱类型，这里会小数运算
        x = parseInt(x / 10);
    }
    return s;
}
const get_sum = (x, y) => {
    return get_single_sum(x) + get_single_sum(y);
}
```