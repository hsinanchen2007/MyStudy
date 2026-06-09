### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */
var romanToInt = function (s) {
  let romanNumberObj = {
    "M": 1000,
    "CM": 900,
    "D": 500,
    "CD": 400,
    "C": 100,
    "XC": 90,
    "L": 50,
    "XL": 40,
    "X": 10,
    "IX": 9,
    "V": 5,
    "IV": 4,
    "I": 1
  }
  let len = s.length
  let res = 0
  let index = 0
  let num
  while (index < len) {
    if (num = romanNumberObj[s.substr(index, 2)]) {
      res += num
      index += 2
    } else {
      res += romanNumberObj[s.substr(index, 1)]
      index++
    }
  }
  return res
};
```

这里主要用到了js对象能通过key快速获取value的特点（类似哈希表），提高查询效率。
然后优先向后移动两位判断是否有匹配项，移动两位没有匹配的移动一位一定是能匹配上的
最后把值累计即可，思路很简单清晰