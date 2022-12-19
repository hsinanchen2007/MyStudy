/**
 * @param {string} num1
 * @param {string} num2
 * @return {string}
 */
var addStrings = function(num1, num2) {
    var long = (num1.length > num2.length) ? num1 : num2;
    var short = (num1.length > num2.length) ? num2 : num1;
    short = new Array(long.length-short.length).fill(0).join('') + short;
    var res = '';
    var carry = 0;
    for(var i=long.length-1;i>=0;i--){
        var temp = (+long[i])+(+short[i])+carry;
        if(temp>=10){
            carry=1;
            temp = temp - 10;
        }else{
            carry=0;
        }
        res = temp+res;
    }
    return carry ? ('1'+res):res;
    
};