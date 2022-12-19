![image.png](https://pic.leetcode-cn.com/b96f498e1c182b32554e12ed09cd4407fe8bee2f3d03512e10f2c2c3841b4d6a-image.png)

### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number} num
 * @return {number}
 */
var numberOfSteps  = function(num) {
  let ans = 0;
  
  if (num === 0) return ans;
  
  while (num > 0) {
    if (num % 2 === 0) {
      num /= 2;
    } else {
      num--;
    }
    ans++;
  }
  
  return ans;
};
```