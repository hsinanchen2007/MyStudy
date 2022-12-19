```js
var sortArrayByParity = function(A) {
    let oddArr = []
    let evenArr = []
    for (let item of A) {
        if(item % 2 == 0) {
           evenArr.push(item) 
        } else {
            oddArr.push(item)
        }
    }
    return evenArr.concat(oddArr)
};
```
