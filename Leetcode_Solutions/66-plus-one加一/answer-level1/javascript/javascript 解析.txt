### 关键点
    - 用数字计算时，避免超出数字类型表示的范围；
    - 加1后，如果进位就是个位数变为0， 不进位改变当前位置的元素即可；
    - 除了整数 0 之外，这个整数不会以零开头；
```javascript []
/**
 * @param {number[]} digits
 * @return {number[]}
 */
var plusOne = function(digits) {
    let len = digits.length;
    for(let i=len-1; i>=0; i--){
        digits[i] = digits[i]+1;
        if(digits[i]>=10){
            digits[i] = digits[i]%10;    
        } else {
             return digits;
        }
    }
    if(digits[0]===0) return [1, ...digits];
    return digits;
};
```

