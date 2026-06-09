### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[][]} A
 * @return {number[][]}
 */
var flipAndInvertImage = function(A) {
    return A.map(item=>{
      return item.reverse().map(t=>{
         return t===1 ? 0 : 1
      })
    })
};
```