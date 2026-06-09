### 解题思路
代码时间复杂度是 O(n)
1. 先对数组排序
2. 比较相邻的两个值
3. 求差值累加步数

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