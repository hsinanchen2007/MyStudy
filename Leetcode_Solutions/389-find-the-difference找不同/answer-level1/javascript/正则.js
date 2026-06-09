### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string} s
 * @param {string} t
 * @return {character}
 */
var findTheDifference = function(s, t) {
  for(let prop of s){
    let reg = new RegExp(prop)
    t = t.replace(reg,'')
  }
  return t
};
```