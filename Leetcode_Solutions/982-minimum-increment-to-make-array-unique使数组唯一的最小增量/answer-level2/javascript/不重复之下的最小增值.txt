题目解读： 所有元素都不重复
解题思路：
从小到大排序，前后比较 后者一定得比前者大。 所以本质上是 统计所有的差距之和
```
var minIncrementForUnique = function(A) {
    A.sort((a,b)=>a-b);
    let left = 0;
    let right = 1;
    let count = 0;//统计
    while(right < A.length){
        if(A[right] <= A[left]){
            var base = (A[left]-A[right])+1;
            A[right] = A[right] + base;
            count = count+ base;
        }
        left++;right++;
    }
    return count;
};
```
