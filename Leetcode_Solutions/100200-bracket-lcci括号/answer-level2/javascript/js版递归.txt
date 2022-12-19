### 解题思路
此处撰写解题思路
递归
### 代码

```javascript
/**
 * @param {number} n
 * @return {string[]}
 */
var generateParenthesis = function(n) {
  const ans = [];
  (function re(str,left,right){
      if(left === n && right === n){
          ans.push(str);
          return;
      }
        if(left < n)  re(str+'(',left+1,right);
        if(left > right && right < n) re(str+')',left,right+1);
  })('',0,0);
  return ans;
};
```