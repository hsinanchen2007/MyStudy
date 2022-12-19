```javascript
/**
 * @param {number} numRows
 * @return {number[][]}
 */
var generate = function(numRows) {
    if (numRows === 0) return [];
    let result = [ [1] ]
    
    while(result.length < numRows) {
        let tmp = []
        const lastItem = result[result.length - 1]
        lastItem.forEach((i, index) => {
            if (index > 0) {
                tmp.push(lastItem[index - 1] + i);
            } else {
                tmp.push(1)
            }
        })
        
        tmp.push(1);
        
        result.push(tmp)
    }
    
    return result;
};
```