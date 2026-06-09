### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} A
 * @return {number}
 */
var minIncrementForUnique = function(A) {
    A.sort((a,b)=>a-b);
    let moves = 0;
    for(let i = 1; i < A.length; i++){
        if(A[i] <= A[i - 1]){
            let pre = A[i];
            A[i] = A[i-1] + 1;
            moves += A[i] - pre;
        }
    }
    return moves;
};
```