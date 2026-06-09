### 解题思路
递归的核心就是有计算就在最外层加个计算，不然都是return 的终止条件

### 代码

```javascript
/**
 * @param {number} x
 * @param {number} n
 * @return {number}
 */
var myPow = function(x, n) {
   if(n ==0 || n ==1){
      return n == 0 ?  1 :  x
   }
    if(n < 0){
       return  myPow(1/x ,-n)
    }
   if(n%2 ==0){
     return  myPow(x * x ,n/2)
    }else{
     return  myPow(x * x ,Math.floor(n/2)) * x 
    }
};

```