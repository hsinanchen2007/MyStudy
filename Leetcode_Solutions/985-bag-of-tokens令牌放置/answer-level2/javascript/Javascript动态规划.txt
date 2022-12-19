三个状态：还能用的令牌token、手上的能量point、手上的分数score，则有
```
 //若point >= token[0],手上的能量还能翻最低能量的令牌，则可以继续换 或者 不动
 dp(token, point, score) = max (
    dp(token.slice(1), point - token[0], score + 1),
    score
 );
```
```
 // 若point < token[0],手上的能量不够翻令牌，则用1分翻最高能量的令牌 或者 不动
 dp(token, point, score) = max (
    dp(token.slice(0, -1), point + token[token.length - 1], score - 1)
    score
 );
```

解：
```
var bagOfTokensScore = function(tokens, P) {
    tokens.sort((prev, next) => prev > next ? 1 : -1);
    function dp(token, point, score = 0) {
        if( token.length === 0 ) return score;
        if( score === 0 && point < token[0] ) return 0;
        if( point >= token[0] ) {
            return Math.max( 
                dp(token.slice(1), point - token[0], score + 1), 
                score
            );
        } else {
            return Math.max(
                score,
                dp(token.slice(0, -1), point + token[token.length - 1], score - 1)
            )
        }
    }
    return dp(tokens, P);
};
```