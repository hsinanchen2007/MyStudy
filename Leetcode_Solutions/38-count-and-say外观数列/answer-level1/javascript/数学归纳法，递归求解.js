### 解题思路
此处撰写解题思路
列出通项公式
![image.png](https://pic.leetcode-cn.com/48fcfce5761cb99fe7084e2087e390cbd8e640830bd50f239fd000e9145cb40b-image.png)


### 代码

```javascript
/**
 * @param {number} n
 * @return {string}
 */
var countAndSay = function(n) {
  if (n === 1) {
    return "1";
  }
  let last = countAndSay(n - 1);
  let count = 1;
  let temp = last[0];
  let rtn = "";
  for (let i = 1; i < last.length; i++) {
    if (last[i] === temp) {
      count++;
    } else {
      rtn = rtn + count + temp;
      count = 1;
      temp = last[i];
    }
  }
  rtn = rtn + count + temp;
  return rtn;
};
```