### 解题思路
这种有序的，递增的一般就是二分查找
两个技巧，找中点的时候，取整数
t * t < 1  但是 (t +1) * (t +1) >1,这个时候就取t 

### 代码

```javascript
var mySqrt = function(x) {
    if(x < 2){return x}
    let l = 0, r = x;
    let mid ;
    while(true){
        mid = Math.round(l + (r -l)/2)
        let t1 = mid * mid
        let t2 = (mid +1) * (mid +1)
        if(t1 == x  || (t1 < x && t2  > x)){
            return mid
        }else if(t1 >x){
            r = mid -1
        }else if(t1 < x){
            l = mid +1
        }
    }
    return  l
};
```