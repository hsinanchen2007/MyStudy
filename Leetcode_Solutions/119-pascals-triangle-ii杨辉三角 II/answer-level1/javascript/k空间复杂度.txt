```javascript
/**
 * @param {number} rowIndex
 * @return {number[]}
 */
var getRow = function(rowIndex) {
    let current = [1]
    while(current.length < rowIndex + 1) {
        let i = current.length
        while(--i > 0) {
            current[i] = current[i] + current[i - 1]
        }
        current.push(1)
    }
    
    return current 
};
```