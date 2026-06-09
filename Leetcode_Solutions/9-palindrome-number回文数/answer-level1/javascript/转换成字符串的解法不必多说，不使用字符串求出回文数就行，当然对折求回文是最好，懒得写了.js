var isPalindrome = function(x) {
    if(x < 0) return false;
    if(x === 0) return true;
    
    let temp = x;
    let _x = 0;
    let n = 10;
    while(temp > 0){
        _x = 10 * _x + temp % 10;
        temp = Math.floor(temp/10)
    }
    return _x === x;
};