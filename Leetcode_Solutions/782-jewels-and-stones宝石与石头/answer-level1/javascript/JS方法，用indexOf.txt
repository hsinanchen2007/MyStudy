
解题思路：遍历判断字符串S中的字符是否包含于字符串J中，var一个变量，符合条件时则加一



```javascript []
/**
 * @param {string} J
 * @param {string} S
 * @return {number}
 */
var numJewelsInStones = function(J, S) {
   var a=0;
   for(var i=0;i<S.length;i++){
       if(J.indexOf(S[i])!=-1){
           a+=1;
       }
   }
   return a;
}
```
