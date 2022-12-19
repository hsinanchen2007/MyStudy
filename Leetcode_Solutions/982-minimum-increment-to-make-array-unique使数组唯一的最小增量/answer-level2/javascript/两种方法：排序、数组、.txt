### 解题思路
方法一：先排序，之后如果当前值小于等于前一个值，就将该值改为前一个数+1；

### 代码

```javascript
/**
 * @param {number[]} A
 * @return {number}
 */
var minIncrementForUnique = function(A) {
    A.sort((a,b) => a-b);
    var count=0;
    for(var i=1;i<A.length;i++){
        if(A[i]<=A[i-1]){
            var pre = A[i];
            A[i]=A[i-1]+1;
            count += A[i]-pre; 
        }
    }
    return count;
};
```
时间复杂度：O(nlog n)，主要的复杂度在排序上

方法二：数组存放
```
var minIncrementForUnique = function(A) {
    var count = new Array(40000).fill(0);
    var max=0;
    for(var item=0; item<A.length;item++ ){
        count[A[item]]++;
        max =Math.max(max,A[item]);
    }
    var res = 0;
    for(var j=0;j<max;j++){
        if(count[j]>1){
            res += count[j]-1;
            count[j+1] += count[j]-1;
        }
    }
    if(count[max]>1){
        var d = count[max]-1;
        res += (1+d)*d/2;
    }
    return res;
};
```
这种解法的时间复杂度不能简单地写成 O(n)。设 n 为数组元素的个数，k 为数组元素的可能取值个数（本期中 k = 40000），这个算法的时间复杂度是 O(n + k)。