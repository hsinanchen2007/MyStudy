### 解题思路
粗暴，排列组合所有可能，挑选其中从左往右累加（reduce）时，左括号树大于右括号的序列即可。

### 代码

```javascript
/**
 * @param {number} n
 * @return {string[]}
 */
var generateParenthesis = function(n) {
    var res = new Set();

    function combination(pre=[], len) {
        if(len > 2*n) {return}
        let a = pre.concat(-1), b = pre.concat(1);
        //
        if(a.reduce((l,c)=>{return l+c}, 0)<=0) {
            if (len === 2*n-1) {
                if(a.filter(x => x === -1).length === n) {
                    res.add(a.join(''))
                }
            } else {
                combination(a, len+1);
            }
            
        }
        //
        if(b.reduce((l,c)=>{return l+c}, 0)<=0) {
            if (len === 2*n-1) {
                if(b.filter(x => x === -1).length === n) {
                    res.add(b.join(''))
                }
            } else {
                combination(b, len+1);
            }
        }
    }

    combination([], 0)

    return Array.from(res).map(x=>{
        return x.replace(/\-1/g, '(').replace(/1/g, ')')
    })
    
};
```