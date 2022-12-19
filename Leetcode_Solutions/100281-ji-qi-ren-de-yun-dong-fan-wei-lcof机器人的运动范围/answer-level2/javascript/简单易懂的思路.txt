### 解题思路
这里的坑是有些孤立的点是可以满足要求<=k的要求, 但是是无法到这个地方去的 比如11*11的k=8, 那么10,0 实际上是满足要求的, 但是第九行都是到不了的, 所以也就无法再到10,0这个点. 明白了这个加上动态规划就能求解了.

### 代码

```javascript
/**
 * @param {number} m
 * @param {number} n
 * @param {number} k
 * @return {number}
 */
var movingCount = function(m, n, k) {
    let count = 0
    // 缓存求解的值
    const cache = {}
    function calc(num) {
        if(cache[num]) return cache[num]
        res = Number(String(num).split('').reduce((a,b) => {
            return Number(a) + Number(b)
        }))
        cache[num] = res
        return res
    }
    // 记录已遍历的点, 防止重复遍历
    const record = [...Array(m)].map(i => [...Array(n)].map(j => 0))
    function move(row, col) {
        // 条件判断, 不超出格子, 不重复遍历
        if(row < 0 || col < 0 || row >= m || col >= n || record[row][col]) return
        // 满足小于k的条件
        if(calc(row) + calc(col) <= k) {
            record[row][col] = 1
            // 有效格子
            count += 1
        }else {
            // 直接返回, 因为无法再往别的地方走了
            return
        }
        // 从0,0遍历而来为+1, 从m-1,n-1遍历而来就是-1
        if(row < m-1)move(row+1, col)
        if(col < n-1)move(row,col+1)
    }
    move(0,0)
    return count
};
```