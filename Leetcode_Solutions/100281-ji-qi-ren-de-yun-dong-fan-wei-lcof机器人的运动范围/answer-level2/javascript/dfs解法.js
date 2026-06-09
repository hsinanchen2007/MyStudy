### 解题思路
因为机器人只能一步一步走，要么往上，往下，往左，往右，因为网格是从（0，0）开始，所有只有往下和往右，
从（0，0）开始往下和右2个方向遍历，遍历每个符合要求的值，会存在重复遍历的情况，要加个二维数组进行标记，当前坐标
是否已经走过
### 代码

```javascript
var movingCount = function(m, n, k) {
  let num = 0
  let visited = []
  // 拆分
  function getNum(i) {
    let cur = 0
    for (; i; i = Math.floor(i /10)) {
      cur += i % 10
    }
    return cur
  }
  // 标记是否走过
  for (let i = 0; i < m; i++) {
    visited.push([])
    for (let j = 0; j < n; j++) {
      visited[i].push(false)
    }
  }
 return (function dd (i, j, si, sj) {
   // 不成立条件: i超出m范围,  j超出n的范围, s+j 大于 k,已经走过
   if (i < 0 || i >= m || j < 0 || j >= n || k < si + sj || visited[i][j]) {
     return 0
   }
   visited[i][j] = true
   // 当前[i,j]已经走过，开始往i+1方向和j+1方向走
   return 1 + dd(i + 1, j, getNum(i + 1), getNum(j)) + dd(i, j + 1, getNum(i), getNum(j + 1))
 })(0,0,0,0)
};

};

```