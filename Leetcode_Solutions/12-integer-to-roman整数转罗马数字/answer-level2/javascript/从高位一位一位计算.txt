### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number} num
 * @return {string}
 */
var intToRoman = function (num) {
  let numStr = num.toString()
  let len = numStr.length
  let res = ''
  for (let i = 0; i < len; i++) {
    let level = len - i
    let d = Number(numStr.charAt(i))
    while (d > 0) {
      if (d < 4) {
        res += getPlace(level)
        d -= 1
      } else if (d === 4) {
        res += getPlace(level) + getPlace(level + 0.5)
        d -= 4
      } else if (d === 9) {
        res += getPlace(level) + getPlace(level + 1)
        d -= 9
      } else {
        // 4-9
        res += getPlace(level + 0.5)
        d -= 5
      }
    }
  }
  return res
};

function getPlace(level) {
  switch (level) {
    case 1:
      return 'I'
    case 1.5:
      return 'V'
    case 2:
      return 'X'
    case 2.5:
      return 'L'
    case 3:
      return 'C'
    case 3.5:
      return 'D'
    case 4:
      return 'M'
  }
}
```

level表示第几位，然后将1-9这几个数按区间划分，计算出相应的罗马数字，最后拼接到一起。
