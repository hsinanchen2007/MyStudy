### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string} A
 * @param {string} B
 * @return {string[]}
 */
var uncommonFromSentences = function(A, B) {
    let arrA = A.split(' ')
    let arrB = B.split(' ')
    let set = new Set(arrA.concat(arrB))
    set.forEach((index,item)=>{
        if ((arrA.indexOf(item) > -1 && arrB.indexOf(item) > -1) || arrA.indexOf(item) !== arrA.lastIndexOf(item) || arrB.indexOf(item) !== arrB.lastIndexOf(item)) {
          set.delete(index)
        }
    })
    return [...set]
};
```