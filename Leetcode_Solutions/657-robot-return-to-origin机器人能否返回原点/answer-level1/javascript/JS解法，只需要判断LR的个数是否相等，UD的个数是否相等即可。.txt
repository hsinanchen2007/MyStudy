```
/**
 * @param {string} moves
 * @return {boolean}
 */
var judgeCircle = function(moves) {
  // 判断左右移动的次数和上下移动的次数是否相等（即 L.count === R.count && U.count === D.count）
  return moves.split('L').length === moves.split('R').length && moves.split('U').length === moves.split('D').length
};
```