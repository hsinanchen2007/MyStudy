/**
 * @param {number} x
 * @return {boolean}
 */

//双指针算法
```
var isPalindrome = function(x){
    if(x < 0) return false;
    let param = x.toString().split('');
    for(let m = 0,n = param.length - 1;m < n;m++,n--){
        if(param[m] !== param[n]){
            return false;
        }
    }
    return true;
}
```
