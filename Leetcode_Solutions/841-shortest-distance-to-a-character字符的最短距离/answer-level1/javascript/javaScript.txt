### 代码

```javascript
/**
 * @param {string} S
 * @param {character} C
 * @return {number[]}
 */
var shortestToChar = function(S, C) {
    let hash = []
    let ret = []
    //记录c字符在s中的位置
    for(let i = 0; i < S.length; ++i)
    {
        if(S[i] == C)
        {
            hash.push(i)
        }
    }
    for(let i = 0; i < S.length;++i)
    {
        let arr = hash.map(item=>Math.abs(item-i))
        ret.push(Math.min(...arr))
    }
    return ret
};
```