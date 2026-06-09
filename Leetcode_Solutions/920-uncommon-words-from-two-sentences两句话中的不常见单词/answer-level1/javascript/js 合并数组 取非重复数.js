```
/**
 * @param {string} A
 * @param {string} B
 * @return {string[]}
 */
var uncommonFromSentences = function(A, B) {
    const result = new Set();
    const repeat = []
    A.split(' ').concat(B.split(' ')).map(item =>{
        if(result.has(item)) {
            result.delete(item)
        } else {
            if(!repeat.includes(item)) {
                result.add(item)
                repeat.push(item)
            }
        }
    })
    return [...result.values()]
};
```
