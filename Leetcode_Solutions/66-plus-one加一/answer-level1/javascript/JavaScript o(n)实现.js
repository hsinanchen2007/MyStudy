1.先看最后一位是不是9，如果不是直接输出
2.如果最后一位是 9，判断当前位数的前一位是否存在，不存在就添加一个新数，新数值为当前值/10;存在就+当前值/10;
3.判断当前值的前一位加完后是否是10；不是直接输出；是的话--。开始下一轮循环

var plusOne = function(digits) {
    const len = digits.length;
    for (let i = len-1; i>=0;i--) {
        digits[i]++;
        if(digits[i]%10 != 0) {
            break;
            return digits;
        }
        else {
            let temp = digits[i];
            digits[i]%=10;
            !digits[i-1]?digits.unshift(temp/10):digits[i-1]+=temp/10;
            if(digits[i-1]%10 != 0 ){
                return digits;
            }
            else {
                digits[i-1]--;
            }
        }
    }
    return digits;

};