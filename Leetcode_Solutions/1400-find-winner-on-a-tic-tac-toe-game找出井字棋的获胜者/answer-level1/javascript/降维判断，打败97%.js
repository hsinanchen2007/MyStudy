### 解题思路
从大佬那学习的思路。

总体来说，因为是有限个，所以可以用枚举
具体方法上，把二维降成一维，这样问题简化很多。

### 代码

```javascript
const tictactoe = moves => {
  const cases = [[0, 1, 2], [3, 4, 5], [6, 7, 8], [0, 3, 6], [1, 4, 7], [2, 5, 8], [0, 4, 8], [2, 4, 6]];
  let grid = new Array(9)
  for (let i = 0; i < moves.length; i++) {
    let [x, y] = moves[i]
    let role = i % 2 ? 'B' : 'A'
    grid[x * 3 + y] = role
  }
  for (let caseItem of cases) { 
    let role = grid[caseItem[0]]
    if (role) {
      if (grid[caseItem[1]] === role && grid[caseItem[2]] === role) { 
        return role
      }
    }
  }
  return moves.length===9?"Draw":"Pending"
};
```