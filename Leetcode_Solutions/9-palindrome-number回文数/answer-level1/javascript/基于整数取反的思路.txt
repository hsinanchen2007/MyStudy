### 解题思路
整数取反后，判断两个值是否相等

### 代码

```javascript
/**
 * @param {number} x
 * @return {boolean}
 */
var isPalindrome = function(x) {
   if(x < 0) {
       return false;
   }
   if(parseInt(x/10) === 0) {
       return true;
   }
   var y = 0;
   var curr = x;
   while(curr !== 0) {
      y = 10*y + curr%10;
      curr = ~~(curr/10);
   }
   if(y == x) {
     return true;
   }
   return false;
};
```