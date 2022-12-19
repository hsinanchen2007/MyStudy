

/**
 * @param {number[]} digits
 * @return {number[]}
 */
//需要考虑当最后一位是9加1等于10的时候向前进一位
//需要考虑当倒数第二位是9加1等于10的时候向前进一位
//...以此类推
//最后需要考虑当第一位数字为9加1等于10的时候向前进一位 也就是说整个数组的长度加1 第一位的数字为1
```
var plusOne = function(digits) {
    let index = digits.length - 1;
    let state = true;
    while(state){
        if(digits[index] === 9){
            digits[index] = 0;
            if(index > 0){
                index--;
            }else{
                digits.unshift(1);
                state = false;
            }
        }else{
            digits[index] = digits[index] + 1
            state = false;
        }
    }
    return digits;
    
};
```
