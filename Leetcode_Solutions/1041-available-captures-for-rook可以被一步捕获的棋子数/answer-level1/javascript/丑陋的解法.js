### 解题思路

定义三个变量x,y,sum分别存储车的横坐标、车的纵坐标、能捕获到的卒的数量。
遍历数组找到车的位置，当找到车的位置后，分别在同一子数组中向前向后遍历，统计横向上能捕获到的数量。
此时如果遍历还没有结束，就在接下来的遍历中寻找`纵坐标===y`一样的卒或者象，不管先找到哪一个都结束遍历。
再从y开始从后往前遍历，寻找再找到车的位置前的遍历中的`纵坐标===y`相同的卒或者象，不管先找到哪一个都结束遍历

### 代码

```javascript
/**
 * @param {character[][]} board
 * @return {number}
 */
var numRookCaptures = function(board) {
  let x, y, sum = 0
  for (let i = 0; i < 8; i++) {
    const site = board[i].indexOf('R')
    if (x !== undefined && y !== undefined) {
      if (board[i][y] === 'p') {
        sum++
        break
      } else if (board[i][y] === 'B') {
        break
      }
    } else {
      if (site >  -1) {
        x = i
        y = site
        for (let j = site - 1; j >= 0; j--) {
          if (board[i][j] === 'p') {
            sum++
            break
          } else if (board[i][j] === 'B') {
            break
          }
        }
        for (let j = site + 1; j < 8; j++) {
          if (board[i][j] === 'p') {
            sum++
            break
          } else if (board[i][j] === 'B') {
            break
          }
        }
      }
    }

  }
  for (let i = y - 1; i >= 0; i--) {
     if (board[i][y] === 'p') {
        sum++
        break
      } else if (board[i][y] === 'B') {
        break
      }
  }
  return sum
};
```