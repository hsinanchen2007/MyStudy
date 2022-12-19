根据N和K递归判断，当前行的第K个，如果k为偶数应该看上一行的第k/2个，否则看上一行的k/2+1个，注意js应为Math.floor(k/2)+1。
然后根据上一行的指定结果判断，如果k为偶数，返回相反的数，如果为奇数，返回相同的数。
```
/**
 * @param {number} N
 * @param {number} K
 * @return {number}
 */

var kthGrammar = function(N, K) {
    let res;
    if(N===1)return 0;
    if(K%2){
        res = kthGrammar(N-1,Math.floor(K/2)+1);
    }else{
        res = kthGrammar(N-1,K/2);
    }
    if(K%2){
        return res;
    }else{
        return res===0?1:0;
    }
    
};
```
