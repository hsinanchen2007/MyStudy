```javascript
/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isSubsequence = function(s, t) {
    //双指针
    let i=0,j=0;
    if(s.length ==0) return true;
    while(j<=t.length){
        if(s[i]==t[j]){
            i++;j++;
            if(i==s.length && j<=t.length) return true;
        }else{
            j++
        }      
    }
    return false;
};
```