//就地修改数组，遍历过程中如果该位为9则直接改为0，循环外的unshift(1)在全为9的情况下运行。
var plusOne = function(digits) {
    for(i=digits.length-1;i>=0;i--){
        if(digits[i]==9){
        digits[i]=0
        }else{
        digits[i]++
        return digits
        }
    }
    digits.unshift(1)
    return digits
}