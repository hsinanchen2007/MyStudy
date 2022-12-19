### 解题思路
保存走过的路，不走回头路即可

### 代码
DFS:
```javascript
var movingCount = function(m, n, k) {
    if(!k) return 1;
    let sum = 0
    const moved = {};
    function canMove(x,y){
        const sub = (x + '' + y).split('').reduce(((sum,key)=>sum+=(+key)),0)
        return sub <= k
    }
    function dfs(x,y){
        if(x < 0 || y < 0 || x >= m || y >= n) return 
        if(!moved[`${x},${y}`] && canMove(x,y)){
            moved[`${x},${y}`] = true
            sum ++;
            dfs(x - 1,y);
            dfs(x + 1,y);
            dfs(x,y - 1);
            dfs(x,y + 1);
        }
    }
    dfs(0,0)
    return sum
};
```

BFS:
```javascript
var movingCount = function(m, n, k) {
    if(!k) return 1;
    let sum = 0
    const step = [[0,1],[1,0],[-1,0],[0,-1]]
    const moved = {};
    const tree = []
    function canMove(x,y){
        const sub = (x + '' + y).split('').reduce(((sum,key)=>sum+=(+key)),0)
        return sub <= k
    }
    tree.push([0,0])
    while(tree.length){
        const [x,y] = tree.shift()
        if(!moved[`${x},${y}`] && x < m && y < n && x>=0 && y >= 0 && canMove(x,y)){
            sum ++;
            moved[`${x},${y}`] = true
            step.forEach(([x2,y2])=>{
                tree.push([x + x2,y + y2])
            })
        }
    }
    return sum
};
```