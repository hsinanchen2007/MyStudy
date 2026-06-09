### 解题思路
此处撰写解题思路
这题要求最小操作次数，使数组里面的数都唯一

这题先按照升序排序
然后遍历数组 如果当前数小于或者等于前一个数，说明需要move
计算当前数和前一个数的差值加一，就实现了当前数比前一个数多1，就实现了最小操作使数组唯一不重复
### 代码

```javascript
/**
 * @param {number[]} A
 * @return {number}
 */
var minIncrementForUnique = function(A) {
    let move = 0;
    A = A.sort((a,b)=>a-b)
    for(let i=1;i< A.length;i++){
        if(A[i] <=A[i-1]){
            let n = A[i-1] - A[i] + 1
            A[i] += n 
            move += n
        }
    }
    return move
};
```