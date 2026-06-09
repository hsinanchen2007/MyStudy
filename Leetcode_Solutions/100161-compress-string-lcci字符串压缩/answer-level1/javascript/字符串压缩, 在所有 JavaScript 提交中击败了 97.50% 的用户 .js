执行用时 :
64 ms
, 在所有 JavaScript 提交中击败了
97.50%
的用户
内存消耗 :
38.8 MB
, 在所有 JavaScript 提交中击败了
100.00%
的用户
```
/**
 * @param {string} S
 * @return {string}
 */
var compressString = function(S) {
    if(!S.length){return S}
    let result = '';
    let arr = S.split('');
    let seed = 1;
    arr.reduce(function(pre,crt,i){
        if(i == 1){
            result = pre;
        }
        
        if(pre == crt){
            seed ++;
        }else{
            result += seed;
            result += crt;
            seed = 1;
        }
        return crt;
    })
    result += seed;
    return (result.length < S.length) ? result : S;
};
```

