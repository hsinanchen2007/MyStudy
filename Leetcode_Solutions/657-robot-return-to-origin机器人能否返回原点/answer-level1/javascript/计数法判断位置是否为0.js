### 解题思路
对每个操作进行计数，最后判断结果是否为0，如果是0那么说明回到了原点，如果不是0，那么说明没有回到原点。

### 代码

```javascript
/**
 * @param {string} moves
 * @return {boolean}
 */
var judgeCircle = function(moves) {
  let up = 0;
  let left = 0;

  for (let index = 0; index < moves.length; index++) {
    switch (moves[index]) {
      case "R":
        left++;
        break;
      case "L":
        left--;
        break;
      case "U":
        up++;
        break;
      case "D":
        up--;
        break;
      default:
        break;
    }
  }

  if (up === 0 && left === 0) {
    return true;
  }
  return false;
};
```