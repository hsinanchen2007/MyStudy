/**
 * @param {number} num
 * @return {number}
 */
var addDigits = function(num) {
    if(num < 10) return num
    num = num % 9
    if(num == 0){
        return 9
    }else{
        return num
    }
};