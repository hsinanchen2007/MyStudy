![image.png](https://pic.leetcode-cn.com/d822046f15e1f934e6ba5dbb81fb8487af9c2a52a62660f62c7f960cf3bdbfcc-image.png)

### 解题思路
...

### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */
var titleToNumber = function(s) {
  let sum = 0, ratio = 1;
  
  for (let i = s.length - 1; i >= 0; i--) {
    let c = s.charAt(i);
    let curr = (c.charCodeAt() - 64) * ratio;
    sum += curr;
    ratio *= 26;
  }
  
  return sum;
};
```