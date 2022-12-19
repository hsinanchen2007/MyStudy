![image.png](https://pic.leetcode-cn.com/489e4a3b14da723050dd4d18a8088bcbf7dbdbe01c9b9b0fabc2cf5f557c4c26-image.png)

### 解题思路
```js
按题目要求统计即可
```

### 代码

```javascript
/**
 * @param {string} S
 * @return {string}
 */

var compressString = function(S) {
  let count = 0, newStr = '';
  
  for (let i = 0, len = S.length; i < len; i++) {
    let c = S.charAt(i);
    if (i === 0 || c !== S.charAt(i - 1)) {
      if (count !== 0) newStr += count;
      newStr += c;
      count = 1;
    } else {
      count++;
    }
  }
  
  if (count !== 0) newStr += count;
  
  return newStr.length < S.length ? newStr : S;
};
```