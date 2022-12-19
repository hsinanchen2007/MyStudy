### 解题思路
1.用 map 统计出每张牌的个数
2. 之前写错了，相邻两个数的最大公约数，并不能表示整体的最大公约数。感谢评论区有人指出。可利用`reduce`循环调用求最大公约数算法，求出整体的最大公约数。
~~2. 依次计算遍历map的时候，相邻的两个数的最大公约数，每组最大公约数都大于等于2，说明map的value 整体的最大公约数，大于等于2~~
### 代码

```javascript
/**
 * @param {number[]} deck
 * @return {boolean}
 */
var hasGroupsSizeX = function (deck) {
  //求最大公约数函数
  function gcb1(num1, num2) {
    if (num1 < num2) {
      [num1, num2] = [num2, num1]
    }
    let temp = num1 % num2
    if (temp == 0) {
      return num2;
    }
    return gcb1(num2, temp)
  }

  let map = new Map()
  for (let i = 0; i < deck.length; i++) {
    if (map.has(deck[i])) {
      map.set(deck[i], map.get(deck[i]) + 1)
    } else {
      map.set(deck[i], 1)
    }
  }
  // 求整体的最大公约数
  let res = Array.from(map.values()).reduce((a, b) => gcb1(a, b))
  return res >= 2
};
```