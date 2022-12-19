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
const movingCount = (m, n, k) => {
    
    const dirs = [1, 0, -1, 0, 1]; // directions
    let visited = new Array(m * n);

    const canWalk = (x, y) => {
        let s1 = x.toString(),
            s2 = y.toString();

        let sum = 0;
        for (const c of s1) sum += c - '0';
        for (const c of s2) sum += c - '0';

        return sum <= k;
    };

    let queue = [[0, 0]];
    visited[0] = true;

    let ans = 1;
    while (queue.length) {
        let cur = queue.shift(),
            x = cur[0], y = cur[1];

        for (let i = 0; i < 4; i++) {
            let tx = x + dirs[i], ty = y + dirs[i + 1];
            if (tx < 0 || ty < 0 || tx >= n || ty >= m 
                    || visited[ty * n + tx] || !canWalk(tx, ty))
                continue;
            
            ans++;
            visited[ty * n + tx] = true;
            queue.push([tx, ty]);
        }    
    }

    return ans;
};
```