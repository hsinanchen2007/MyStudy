### 解题思路
直接拿到第一个数组元素匹配后面的所有的相同则true字符串添加，只要false就返回str（不过要注意判断的是后面的元素下标是否溢出）

### 代码

```javascript
/**
 * @param {string[]} strs
 * @return {string}
 */
var longestCommonPrefix = function(strs) {
    if(strs.length === 0) {
        return "";
    }
   const length = strs[0].length;
   let index = 0;
   let str = "";
   while(index <= length -1) {
       let bool = true;
       for(let j = 1;j < strs.length;j++) {
         if(strs[0][index] === strs[j][index] ) {
             bool = true;
         } else {
          bool = false;
          break;
         }
     }
     if(bool) {
           str = bool ? str + strs[0][index] : str;
         } else {
             return str;
         }
         index++;
   }
   return str; 
};
```