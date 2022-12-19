## JavaScript队列解法

```javascript []
/**
 * @param {string} astr
 * @return {boolean}
 */
var isUnique = function(astr) {
    let temp;
    let arr = astr.split('')
    for(let i = 0; i < arr.length; i++){
        temp = arr.pop()
        if(arr.indexOf(temp) != -1 ) return false
    }
    return true
}; 
```
