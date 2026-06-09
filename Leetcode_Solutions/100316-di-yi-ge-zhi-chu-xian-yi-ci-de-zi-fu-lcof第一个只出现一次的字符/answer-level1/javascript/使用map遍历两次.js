### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string} s
 * @return {character}
 */
var firstUniqChar = function(s) {
  let map = new Map();
  let res = ' ';
  if(!s.length) {
    return ' ';
  }
  for(let i=0;i<s.length;i++) {
      if(map.has(s[i])) {
          map.set(s[i], true);
      } else {
          map.set(s[i], false);
      }
  }
  for(let j=0,len=s.length;j<len;j++) {
      if(!map.get(s[j])) {
         res=s[j];
         break;
      }
  }
  return res;
};
```