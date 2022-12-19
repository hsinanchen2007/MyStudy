### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number} numRows
 * @return {number[][]}
 */
var generate = function(numRows) {
    if(numRows===0) return []
    let array = []
    array[0] = [1]
    for(let i=1; i<numRows; i++) {
        let arr = []
        arr[0] = 1
        arr[i] = 1
        for(let j=1; j<i; j++) {
            arr[j] = array[i-1][j]+array[i-1][j-1]
        }
        array[i] = arr
    }
    return array
};
```