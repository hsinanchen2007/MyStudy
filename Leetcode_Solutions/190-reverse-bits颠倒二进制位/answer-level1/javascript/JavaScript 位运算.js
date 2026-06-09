```javascript
/**
 * @param {number} n - a positive integer
 * @return {number} - a positive integer
 */
var reverseBits = function(n) {
    let res = 0;
    for(let i=0;i<32;i++){
        //res左移，然后取n的最低位，加到res的最低位
        res = (res << 1) + (n & 1);
        //n右移
        n = n>>1;
    }
    //把符号位换成0
    return res >>> 0;
};
```