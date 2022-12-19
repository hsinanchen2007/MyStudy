```js
var isMonotonic = function(A) {
    let isUp = false;
    let isDown = false;
    if (A.length >= 3) {
        for (let i = 0; i < A.length-1; i++) {
            if (A[i] < A[i+1]) {
                // 前面比后面小
                isUp = true
            } else if (A[i] > A[i+1]) {
                // 前面比后面大
                isDown = true
            }
        }
    }
    // 同时出现 isUp = true && isUp = true，说明有问题
    return !(isUp && isDown)
};
```
