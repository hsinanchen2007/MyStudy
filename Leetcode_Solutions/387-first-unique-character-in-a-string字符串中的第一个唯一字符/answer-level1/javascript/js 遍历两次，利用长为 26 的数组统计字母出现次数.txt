![image.png](https://pic.leetcode-cn.com/a33eeab0c1ba94b6bdae9410f7c600cfd057116512e9b32ab0ce9b4064bef11d-image.png)

### 解题思路
```js
  因为字母只有26个，将所有字母统计到 26 长度的数组中，返回第一个出现次数为 1 的字母
  
  字母的对应的 code：
  a - z
  97 - 122
```

### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */

var firstUniqChar = function(s) {
  let arr = new Array(26).fill(0), index = -1;
  
  for (let i = 0; i < s.length; i++) {
    let cIndex = s.charAt(i).charCodeAt() - 97;
    arr[ cIndex ]++;
  }
  
  for (let i = 0; i < s.length; i++) {
    let c = s.charAt(i);
    let cIndex = c.charCodeAt() - 97;
    if (arr[cIndex] === 1) {
      index = i;
      break;
    }
  }
  
  return index;
};
```