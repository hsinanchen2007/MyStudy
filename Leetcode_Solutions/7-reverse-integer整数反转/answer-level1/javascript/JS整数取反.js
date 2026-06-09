### 解题思路
整数取反，就是通过除以10取余，将余数在乘以10加起来。每次取余后，需要将整数位数减少一位。

### 代码

```javascript
/**
 * @param {number} x
 * @return {number}
 */
var reverse = function(x) {
   var max = Math.pow(2,31) - 1;
   var min = -Math.pow(2,31); 
   var y = 0;
   while(x !=0){
     y= y*10 + x%10;
     x = ~~(x/10);
   }
   if(y > max){
       y = 0;
   }
   if(y<min){
       y = 0;
   }
  return y;
};
```