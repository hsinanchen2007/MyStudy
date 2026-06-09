### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string[]} A
 * @return {string[]}
 */
var commonChars = function(A) {
    let deleteA = [].concat(A);
    let word = A[0],
        res = [];
    for(let str of word) {
        let count = 0;
        for(let i = 1; i < A.length; i++) {
            if(deleteA[i].includes(str)) {
                deleteA[i] = deleteA[i].replace(str, "");
                count ++;
            }
        }
        if(count === A.length - 1) {
            res.push(str)
        }
    }
    return res;
};
```