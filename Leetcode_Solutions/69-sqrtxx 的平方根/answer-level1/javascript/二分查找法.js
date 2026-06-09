/**
 * @param {number} x
 * @return {number}
 */
```
var mySqrt = function(x) {
    if(x <= 1 ) return x;
    let left = 0;
    let right = x-1;
    while(left <= right){
        let mid =  (left+right) >>> 1;
        let s = mid * mid;
        if(s === x){
            return mid
        }else if(s > x){
            right = mid - 1
        }else{
            left = mid +1
        }
    }
    
    return right
};
```
