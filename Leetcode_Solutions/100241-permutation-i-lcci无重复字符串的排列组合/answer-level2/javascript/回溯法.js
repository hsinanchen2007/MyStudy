### 解题思路
回溯法

### 代码

```javascript
/**
 * @param {string} S
 * @return {string[]}
 */
var permutation = function(S) {
    let res = []
    function backtrack(i, cur) {
        // cur.length > 0 && res.push(cur)
        if(cur.length === S.length) res.push(cur)
        // if(i >= S.length) return
        // else if(cur.length >= S.length) return
        for(let j = 0; j < S.length; j++) {
            // console.log(S[j],cur, cur.indexOf(S[j]))
            if(cur.indexOf(S[j]) == -1) {
                backtrack(j, cur + S[j])
            }
        }
    }
    backtrack(0, '')
    return res
};
```