### 解题思路
从[0,0]作为起点开始走，只需要向右走和向下走

### 代码

```javascript
/**
 * @param {number} m
 * @param {number} n
 * @param {number} k
 * @return {number}
 */
var movingCount = function(m, n, k) {
    this.ans = 0;
    this.visited = [m];
    for(var i = 0; i < m; i++){
        this.visited[i] = [n].fill(false);
    }
    dfs(0, 0, m, n, k);
    return ans;
};

var dfs = function(x, y, m, n, k){
    var a = x%10, aa = parseInt(x/10);
    var b = y%10, bb = parseInt(y/10);
    if(x >= m || y >= n || a+aa+b+bb > k || this.visited[x][y]) return;
    this.visited[x][y] = true;
    ans++;
    dfs(x, y + 1, m, n, k);
    dfs(x + 1, y, m, n, k);
}
```