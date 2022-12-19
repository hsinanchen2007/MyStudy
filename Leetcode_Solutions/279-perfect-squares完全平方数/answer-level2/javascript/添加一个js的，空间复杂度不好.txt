### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number} n
 * @return {number}
 */
var numSquares = function (n) {
    let step = 1;
    const q = [0];
    const visited = new Map();
    visited.set(0, true);
    while (q.length) {
        for (let i = q.length; i > 0; i--) {
            const cur = q.shift();
            for (let j = 1; ; j++) {
                let next = j * j + cur;
                if (next > n) break;
                if (next === n) return step;
                if (!visited.get(next)) {
                    q.push(next);
                    visited.set(next, true);
                }
            }
        }
        step++;
    }
};

```