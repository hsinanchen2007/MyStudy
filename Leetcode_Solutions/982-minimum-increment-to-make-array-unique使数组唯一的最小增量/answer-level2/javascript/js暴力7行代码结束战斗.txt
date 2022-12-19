没什么好说的
```js
var minIncrementForUnique = function(A) {
    A.sort((a, b) => a - b);
    let move = 0;
    for(let i = 1; i < A.length; i++) {
        if(A[i] <= A[i - 1]) [A[i], move] = [A[i - 1] + 1, move + A[i - 1] + 1 - A[i]];
    }
    return move;
};
```
