### 解题思路
先排序，然后遍历数组，如果A[i]>=A[i+1],A[i+1]++,继续判断A[i+1]>=A[i+2],满足A[i+2]++,以此类推
最终输出次数count
时间复杂度主要在排序上
但是6000多毫秒也太慢了吧- -

### 代码

```javascript
/**
 * @param {number[]} A
 * @return {number}
 */
var minIncrementForUnique = function(A) {
    var count=0;
    A.sort((a,b)=>(a-b));
    len=A.length;
    for (let i=0;i<len;i++){
        let j=i;
        if (A[i]>=A[i+1]){
            A[i+1]++
            count++
        }
        while(A[j+1]>=A[j+2]){
            A[j+2]++
            count++
            j++
        }
    }
    return count
};
```