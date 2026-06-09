### 解题思路
**方法一：枚举 + 广度优先搜索BFS**
广度优先搜索BFS（Breadth First Search），就是从**起点出发**，每次都尝试访问**同一层的节点**，如果同一层都访问完了，再访问**下一层**，最后广度优先搜索找到的路径就是从起点开始的**最短合法路径**。

**上下左右相邻**的新鲜**🍊**=一个腐烂🍊尝试访问的**同一层的节点**
**路径长度**=新鲜🍊被**腐烂的时间**
对每一个bad🍊进行BFS

**方法二：多源广度优先搜索BFS**
**超级源点**

### 代码

```javascript
var orangesRotting = function(grid) {
    let times = 0,
        cnt = 0, // fresh oranges counter🍊
        queue = []
    //inital organe queue , good->record cnt, bad->push into a queue
    for (let i = 0; i < grid.length; i++) {
      for (let j = 0; j < grid[i].length; j++) {
        if (grid[i][j] === 2) queue.push( [i, j, 0] ) // 3rd rot time=0
        if (grid[i][j] === 1) cnt++
      }
    }
    
    //run rot function
    while (queue.length ) {
      let curr = queue.shift()  // delete and return 1st element of queue
      times = curr[2] //rot time
      rot(curr[0], curr[1], curr[2])
    }
    // create a "rot" function
    function rot(row, col, t) {
      // 4 direction
      let d = [ [-1, 0], [0, 1], [1, 0], [0, -1] ];
      for (let i = 0; i < 4; i++) {
        let r = row + d[i][0]
        let c = col + d[i][1]
        // r!∈(0,row) c!∈(0,col)  grid[r][c] !== 1 ->continue(pass)
        // else grid[r][c]=2 (good orange rot)-> cnt-- 
        if (r < 0 || r >= grid.length || c < 0 || c >= grid[0].length || grid[r][c] !== 1) {
            continue
        }else{
            grid[r][c] = 2
            cnt--
            queue.push( [r, c, t+1] )
        }
      }
    }
    
    return cnt > 0 ? -1 : times
  }

```
🍊