### 解题思路
试了下java的精选算法，用js实现，运行结果比我自己写的这个还慢，也多占了.1M的内存，不明白

### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */
var romanToInt = function(s) {
   s = s.split('');
     var obj = {
           'I' : 1,
           'V' : 5,
           'X' : 10,
           'L' : 50,
           'C' : 100,
           'D' : 500,
           'M' : 1000
       }
   var sum = 0;
   for(var i = 0;i<s.length;i++){
       var v = 0;
       if(i == (s.length - 1)) {
           v = obj[s[i]];
       }else {
         v = obj[s[i]] >= obj[s[i + 1]] ?  obj[s[i]] : -obj[s[i]] ;
       }
       sum = sum + v*1;
   }
   return sum;
};
```