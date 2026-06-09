![image.png](https://pic.leetcode-cn.com/2cf03bce11c8ecf977aa5c3ef6208e83244bc91cb5ced5e0e937b302752a9757-image.png)

### 解题思路

### 代码

```javascript
/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isSubsequence = function(s, t) {
  if (s === '' && t === '') return true;
  
  let ans = false,
      start = 0,
      end = s.length;
  
  for (let i = 0, len = t.length; i < len; i++) {
    if (s.charAt(start) === t.charAt(i)) {
      start++;
    }
    
    if (start === end) {
      ans = true;
      break;
    }
  }
  
  return ans;
};
```