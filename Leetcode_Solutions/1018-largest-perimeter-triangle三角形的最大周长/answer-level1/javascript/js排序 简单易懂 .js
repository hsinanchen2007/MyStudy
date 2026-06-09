```
/**
 * @param {number[]} A
 * @return {number}
 */

var largestPerimeter = function(A) {
    let sortA = A.sort((a, b) => b - a)
    let len = A.length
    for(let i = 0; i <= len - 3; i++){
        if(sortA[i] < sortA[i+1] + sortA[i+2]){
            return sortA[i] + sortA[i+1] + sortA[i+2]
        }
    }
    return 0

};
```
