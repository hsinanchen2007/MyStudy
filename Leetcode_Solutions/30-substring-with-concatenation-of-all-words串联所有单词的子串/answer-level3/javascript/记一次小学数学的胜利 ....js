![批注 2019-09-28 224454.png](https://pic.leetcode-cn.com/76f3bf60d5e68a1ed754131fb3b5da3c8d9516b077a7837f06a3037a086fc19c-%E6%89%B9%E6%B3%A8%202019-09-28%20224454.png)

这个解法比较怪奇 ... 基于小学知识加法交换律 ... 用效能换空间 ... 代码如下 ...

```javascript
var findSubstring = function(s, words) {
  
    if ( "undefined" == typeof words[0] ) return [];

    const calc = ( s, n ) => {
        for ( var r = 0, a = 0, i = parseInt( s.length / n ) - 1; i > -1, a = s.charCodeAt( i * n ); -- i )
            for ( let j = 0; j < n; )
                r += a * s.charCodeAt( i * n + j ) * ++ j;

        return r;
    };
    
    const l = words[0].length;
    const t = l * words.length;
    const r = [];

    let c = 0;
    for ( let v of words ) c += calc( v, l );
    
    for ( let i = s.length - t; i > -1; -- i )
        if ( c === calc( s.substr( i, t ), l ) ) r.push( i );

    return r;

};
```

耗时主要在把字符串哈希成整形的过程上 ... 一时间也想不到更快的方法了 ...

这怎么想都不算是个标准解法 ... 写着好玩的成分更多 ... 供参考 ...