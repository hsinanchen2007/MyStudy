### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string} s
 * @return {string}
 */
var replaceSpace = function(s) {
   var str = []
   for(let i=0;i<s.length;i++) {
     if(s[i]===' ') {
       str.push('%20');
     } else {
        str.push(s[i]);
     }
   }
   return str.join('');
};
```