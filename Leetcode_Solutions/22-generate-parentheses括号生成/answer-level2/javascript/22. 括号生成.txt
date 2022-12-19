### 解题思路
几个月前刷的题,写完就忘...

### 代码

```javascript
/**
 * @param {number} n
 * @return {string[]}
 */
var generateParenthesis = function(n) {
    let results = [[""]]
    for(let i = 1; i <= n; i++){
        let _r = []
        for(let j = 0; j < i; j++){
            let left = results[j], right = results[i - j - 1]
            for(let x = 0; x < left.length; x++){
                for(let y = 0; y < right.length; y++){
                    _r.push("(" + left[x] + ')'+ right[y])
                }
            }
        }
        results.push(_r)
    }
    return results[results.length - 1]
};
```