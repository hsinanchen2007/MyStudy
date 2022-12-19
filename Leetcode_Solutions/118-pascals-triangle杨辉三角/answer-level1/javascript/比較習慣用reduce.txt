### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number} numRows
 * @return {number[][]}
 */
var generate = function(numRows) {
    const genRow = (row = []) => {
      return row.reduce((arr, n, i, row)=>{
        arr[i + 1] =  n + (row[i + 1] || 0)
        return arr
      },[1])
    }
    const ret = []
    while(ret.length < numRows){
      ret[ret.length] = genRow(ret[ret.length - 1])
    }
    return ret
};
```