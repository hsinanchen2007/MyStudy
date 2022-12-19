### 解题思路
先进行数组排序，再循环数组；
当前项与前一个比较，如果小于等于前一个，计算差值加一，累加记录并替换当前A[i]的值，依次往后进行；
累计的记录即为操作次数。

### 代码

```javascript
/**
 * @param {number[]} A
 * @return {number}
 */
var minIncrementForUnique = function(A) {
    let num=0;
    A.sort((a,b)=>a-b);
    for(let i=1;i<A.length;i++){
        if(A[i]<=A[i-1]){
            num+=(A[i-1]-A[i]+1)
            A[i]+=(A[i-1]-A[i]+1)
        }
    }
    return num
};
```