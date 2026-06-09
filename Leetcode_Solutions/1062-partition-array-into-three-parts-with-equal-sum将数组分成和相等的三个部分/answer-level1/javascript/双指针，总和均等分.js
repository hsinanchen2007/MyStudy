### 解题思路
方法一、
要想能够均匀分成三部分，则每一部分都应该为和的三分之一
如果还没遍历完整个数组就找到了三个等于和的三分之一的数组，说明后面的值的和为零
### 代码

```javascript
/**
 * @param {number[]} A
 * @return {boolean}
 */
var canThreePartsEqualSum = function(A) {
    var count =0;
    var sum=0;
    var s=0;
    for(var i=0;i<A.length;i++){
        sum += A[i];
    }
    if(sum%3!=0) return false;
    for(i=0;i<A.length;i++){
        s += A[i];
        if(s == sum /3){
            count++;
            s=0;
        }
    }
    return count >=3;
};
```
方法二、双指针
```
var canThreePartsEqualSum = function(A) {
    var left=0,right= A.length-1;
    var leftsum=A[left],rightsum=A[right];
    var sum=0;
    if(sum%3 != 0) return false;
    for(var i=0;i<A.length;i++){
        sum += A[i];
    }
    while((left+1)<right){
        if(leftsum==sum/3 && rightsum==sum/3){
            return true;
        }
        if(leftsum != sum/3){ 
            left++
            leftsum += A[left];
        }
        if(rightsum != sum/3){
            right--;
            rightsum += A[right];
        }
        
    }
    return false;
};
```
