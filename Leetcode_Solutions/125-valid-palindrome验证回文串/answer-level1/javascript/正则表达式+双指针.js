```
/**
 * @param {string} s
 * @return {boolean}
 */
var isPalindrome = function(s) {
    var reg = /[0-9a-zA-Z]/i;
    var s = s.toLowerCase();
    for(let i=0,j=s.length-1,len=s.length;i<=j;){
        while(!reg.test(s[i])){
            i++;
        }
        while(!reg.test(s[j])){
            j--;
        }
        if(s[i] === s[j]){
            i++;
            j--;
        } else{
            return false;
        }
    }
    return true;
};
```
