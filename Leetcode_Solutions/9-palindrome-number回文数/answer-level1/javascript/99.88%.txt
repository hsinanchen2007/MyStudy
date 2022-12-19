```
/**
 * @param {number} x
 * @return {boolean}
 */
var isPalindrome = function(x) {
    let res =0,t=x
    if(t<0) return false
    if(0<=t&&t<10) return true
    while(t>=1){
        res = res*10+parseInt(t%10)
        t=parseInt(t/10)
    }
    return res==x?true:false
};
```
