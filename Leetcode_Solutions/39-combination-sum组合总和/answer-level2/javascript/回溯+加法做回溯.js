### 解题思路
通过排序后，做的加法剪枝。不排序会出现误减的问题，暂时还不会...
### 代码

```javascript
/**
 * @param {number[]} candidates
 * @param {number} target
 * @return {number[][]}
 */
var combinationSum = function(candidates, target) {
    var arr = []
    help([],0, 0,candidates.sort((a,b)=>a-b),target)
    return arr
    function help(cur, sum, index, candidates, target) {
        debugger
        if (sum === target) {
            return arr.push(cur)
        }
        for (var i = index; i < candidates.length; i++) {
            var c = candidates[i]
            if (c +sum > target) break
            cur.push(c)
            help(cur.slice(), sum+c, i,candidates, target)
            cur.pop()
        }
    }
};
```