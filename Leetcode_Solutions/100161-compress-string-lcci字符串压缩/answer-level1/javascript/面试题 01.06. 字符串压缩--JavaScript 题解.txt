时间复杂度 O(n)，空间复杂度O(1)
循环字符串，记录相等的字符的个数，如果不相等则加入新的字符，并重新计算个数
```
var compressString = function(S) {
    if (!S.length) return '';
    var res = S[0];
    var count = 1;

    for(var i = 1; i < S.length; i++){
        if(S[i] === S[i-1]){
            count++;
        }else{
            res += count;
            res += S[i];
            count = 1;
        }
    }
    res+=count;
    return res.length < S.length ? res : S;
};
```
