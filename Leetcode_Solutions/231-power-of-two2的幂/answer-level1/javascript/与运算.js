### 解题思路
核心思想就是 2 的 n 次方，转化成二进制以后，就是只有一个1存在的二进制
然后消掉这个1 ，看是不是0

### 代码

```javascript
/**
 * @param {number} n
 * @return {boolean}
 */
var isPowerOfTwo = function(n) {
   if(n >0 && (n & (n -1)) ==0)
   {
       return true
   }
   return false
};
```