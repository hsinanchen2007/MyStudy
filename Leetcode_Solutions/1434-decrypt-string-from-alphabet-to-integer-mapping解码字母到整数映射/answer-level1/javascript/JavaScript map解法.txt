### 解题思路
使用一个map，从末尾往前遍历字符串每个字符，遇到#将#前的两个数字作为一体
![leetcode1309.png](https://pic.leetcode-cn.com/9f393e3c3eed5bc16e03bc02493558e38d97f83b422322639beab9069cf5d71e-leetcode1309.png)


### 代码

```javascript
/**
 * @param {string} s
 * @return {string}
 */
var freqAlphabets = function(s) {
  const map = {"1":"a","2":"b","3":"c","4":"d","5":"e","6":"f","7":"g",
    "8":"h","9":"i","10":"j","11":"k","12":"l","13":"m","14":"n","15":"o",
    "16":"p","17":"q","18":"r","19":"s","20":"t","21":"u","22":"v",
    "23":"w","24":"x","25":"y","26":"z"}
  const stack = []
  const len = s.length
  for (let i = len - 1; i >= 0; i--) {
    if (s[i] !== '#') {
      stack.unshift(map[s[i]])
    } else {
      stack.unshift(map[`${s[i - 2]}${s[i - 1]}`])
      i-=2
    }
  }
  return stack.join('')
};
```