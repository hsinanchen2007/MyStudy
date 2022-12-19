### 解题思路
先排序后遍历。小→大排序后比较相邻两位的大小，若A[i-1] >= A[i],则令A[i] += 1。就是耗时太长了..

### 代码

```javascript
/**
 * @param {number[]} A
 * @return {number}
 */
var minIncrementForUnique = function(A) {
    if(A.length == 0)
        return 0;
A.sort(function(a,b){return a-b});
var count = 0;
var i;
for(i = 1; i < A.length; i++){
    /*while(A[i-1] >= A[i]){
        A[i]+=1;
        count++;*/

    //觉得太复杂了突然想到另一种方式，尝试了一下用时少了很多；
    if(A[i-1] >= A[i]){
        var a = A[i-1]-A[i]+1;  //判断相邻两位的差值+1后得到本应重复move的次数
        A[i] += a;
        count += a;     
}
}
    return count;
};
```