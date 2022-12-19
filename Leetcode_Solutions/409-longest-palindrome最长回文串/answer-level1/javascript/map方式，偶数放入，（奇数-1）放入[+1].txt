```javascript []
var longestPalindrome = function(s) {
    let map = new Map();
    for(let i of s){
        map.set(i, map.has(i)?map.get(i)+1:1);
    }
    let res = 0, maxOdd = 0;
    let hasOne = false;
    map.forEach(function(v, k){
        if(v%2 == 0){
            res+=v;
        }else{
            if(v==1){
                hasOne=true;
            }
            maxOdd+=(v-1);
        }
    })
    return res+maxOdd+(maxOdd>0||hasOne?1:0);
};
```
