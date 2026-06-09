### 解题思路

不用额外真不会

### 代码

```javascript
/**
 * @param {number[][]} matrix
 * @return {void} Do not return anything, modify matrix in-place instead.
 */
var rotate = function(matrix) {
    let arr = [...matrix]
    for(let i = 0; i < arr.length; i++){
        let list = []
        for(let j = 0; j < arr[0].length ; j++){
            list.push(arr[j][i])
        }
        matrix[i] = list.reverse()
    }
    return matrix
};
```