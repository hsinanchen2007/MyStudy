```
/**
 * @param {string} s
 * @return {number}
 */
var balancedStringSplit = function(s) {

    let l=0,r=0;
    let ans=0;
    for(let i=0;i<s.length;i++){
        if(s[i] == 'L'){
            l++;
        }else{
            r++;
        }

        if(l == r){
            ans++;
            l = r = 0;
        }
    }

    return ans;
};
```
