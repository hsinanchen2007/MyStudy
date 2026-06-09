### 解题思路
其实是个比较取巧，并不普适的解法，主体思想是二分法。
判断思路是一旦mid在调整后仍然取值不变，就返回mid。
因为这个题是取整的，而不是要求与n最接近的整数，所以mid那块用的是floor而不是ceil。
最后,这个解法的bug是n=1时会返回0，所以再处理一下这个特殊输入值就行了。

### 代码

```javascript
/**
 * @param {number} x
 * @return {number}
 */
var mySqrt = function(x) {
    if(x===1){return 1}
    let left = 0;
    let right = x;
    let mid;
    while(1){
        mid = Math.floor((left+right)/2);
        if(mid**2===x){
            return mid;
        }else if(mid**2>x){
            right=mid;
        }else{
            left=mid;
        }
        mid2 = Math.floor((left+right)/2);
        if(mid===mid2){return mid}
    }
};
```