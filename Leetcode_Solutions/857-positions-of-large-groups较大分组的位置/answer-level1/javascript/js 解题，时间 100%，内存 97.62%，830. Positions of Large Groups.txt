### 解题思路
通过循环获取连续的字符串，当前字符与前一个字符是否相同，判断连续次数是否大于2
![830. Positions of Large Groups.png](https://pic.leetcode-cn.com/67c16a63af1685594ec6f6ddad20f991a0e1b81aa6f1f7a5aedff656d23fdd9b-830.%20Positions%20of%20Large%20Groups.png)

### 代码

```javascript
/**
 * 830. Positions of Large Groups
 * https://leetcode-cn.com/problems/positions-of-large-groups/
 * @param {string} S
 * @return {number[][]}
*/
var largeGroupPositions = function (s) {
  if (s.length < 3) {
    return [];
  }
  let start = 0;
  let end = 0;
  let count = 1;
  let res = [];
  for (let i = 1; i < s.length; i++) {
    if (s[i] === s[i - 1]) {
      count++;
      end = i
    } else {
      if (count > 2) {
        res.push([start, end]);
      }
      count = 1;
      start = i;
    }
  }
  if (count > 2) {
    res.push([start, end]);
  }
  return res;
};
```