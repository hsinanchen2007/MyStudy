### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */
var longestPalindrome = function(s) {
      var obj = {};
      var cont = 0;
      for(var i = 0;i<s.length;i++){
          if(obj[s.charAt(i)]){
              obj[s.charAt(i)] += 1;
          } else {
               obj[s.charAt(i)] = 1;
          }
      }
      for(var key in obj) {
          if(obj[key] %2 === 1 && cont%2 === 0) {
              cont = cont + 1
          } 
        cont += (~~(obj[key]/2))*2
      }
  return cont;
}
```