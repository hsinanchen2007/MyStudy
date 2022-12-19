### 解题思路
把座位按 `(2-3)` `(4-5)` `(6-7)` `(8-9)`划分四个状态
代码中标记为: `flag[0]` | `mid[1]` | `mid[0]` | `flag[1]`
hash遍历
**防止超时的优化**
1.减少判断次数
2.跳过空行 用`2*n总次数`减去`占用`的人数
- 如果中间没有坐人
  - 判断两边是否坐人
  - 两边任意一边坐人,总次数-1
  - 两边没坐人, 总次数-0
- 如果中间有人
  - 如果坐了一半,并且旁边没坐人 总次数-1
  - 如果坐满了 总次数-2

### 代码

```javascript
/**
 * @param {number} n
 * @param {number[][]} reservedSeats
 * @return {number}
 */
var maxNumberOfFamilies = function (n, reservedSeats) {
  let hasSeats = {};
  for (has of reservedSeats) {
    const [x, y] = has;
    hasSeats[x] = hasSeats[x] || {}
    hasSeats[x][y] = 1;
  }

  const maxLineSeats = (has) => {
    const curLine = hasSeats[has];
    let flag = [0, 0], mid = [0, 0]
    for (k in curLine) {
      if (k <= 3 && k >= 2) flag[0]++
      if (k <= 5 && k >= 4) mid[0]++
      if (k >= 6 && k <= 7) mid[1]++
      if (k <= 9 && k >= 8) flag[1]++
    }
    if (mid[0] == 0 && mid[1] == 0) { //中间没坐人
      if (flag[0] > 0 || flag[1] > 0)
        return -1 // 两边坐人 
      else return 0
    }
    // 任意一边有人,另一边没人 总次数-1
    if (mid[0] == 0 && flag[0] == 0 || mid[1] == 0 && flag[1] == 0) return -1
    // 剩下的都坐了人 总次数-2
    return -2
  }
  let result = 2 * n;
  for (k in hasSeats) {
    result += maxLineSeats(k)
  }
  return result
};
```