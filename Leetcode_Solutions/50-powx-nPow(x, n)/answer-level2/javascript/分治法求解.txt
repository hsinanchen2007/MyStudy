### 解题思路
采用分治的思想，一分二，二分四。
注意点：此处分为两部分以后，myPow( x , n/2) * myPow( x , n/2)  === myPow(x* x , n/2)
终止条件是 n==0 n==1 ，当n被分到1 以后，直接返回x
还要注意n为负数的情况
### 代码

```javascript
/**
 * @param {number} x
 * @param {number} n
 * @return {number}
 */
var myPow = function(x, n) {
    if(n ==0 || n ==1) {
        return n ==0 ? 1: x
    }else if(n < 0){
        return myPow(1/x, Math.abs(n))
    }else{
        return n % 2 == 0 ? myPow(x * x , n/2) :  myPow(x * x ,Math.floor(n/2))* x
    }
};
```