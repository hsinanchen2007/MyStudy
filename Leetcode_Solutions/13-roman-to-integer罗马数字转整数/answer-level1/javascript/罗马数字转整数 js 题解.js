### 解题思路
1. 把罗马数字对应整数的规则存到哈希表里进行映射

2. 罗马数字分两种情况，一种是正常的一个一个相加的，一种是小的数字在前面，需要用后一个数字减去前面一个数字，这种情况

3. 遍历罗马数字
   - 如果跟后一个数字组合，不在哈希表里，则直接跟上一次的结果相加，跳到下一个数字
   - 如果跟后一个数字组合，结果在哈希表里，则跟该组合的值跟上一次的结果相加，跳到下下个数字

### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */
var romanToInt = function(s) {
  const map = {
    I: 1,
    V: 5,
    X: 10,
    L: 50,
    C: 100,
    D: 500,
    M: 1000,
    IV: 4,
    IX: 9,
    XL: 40,
    XC: 90,
    CD: 400,
    CM: 900
  };

  const { length } = s;
  let res = 0;

  for (let i = 0; i < length; ) {
    if (map[s[i] + s[i + 1]]) {
      res += map[s[i] + s[i + 1]];
      i += 2;
    } else {
      res += map[s[i]];
      i += 1;
    }
  }
  return res;
};
```