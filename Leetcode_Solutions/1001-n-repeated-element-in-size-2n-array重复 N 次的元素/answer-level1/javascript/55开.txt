### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} A
 * @return {number}
 */
var repeatedNTimes = function(A) {
    let len2 = A.length/2
    let list = A.sort((a,b)=>a-b)
    if(list[len2 - 1]===list[len2 - 2]){
      return list[len2 - 1]
    } else {
      return list[len2]
    }
};
```