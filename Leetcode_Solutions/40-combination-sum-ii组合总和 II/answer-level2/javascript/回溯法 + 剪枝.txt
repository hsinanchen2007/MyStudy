### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} candidates
 * @param {number} target
 * @return {number[][]}
 */
var combinationSum2 = function(candidates, target) {
    var len = candidates.length;
    var res = [];
    var path = [];

    candidates.sort((a, b) => a - b);
    backtrack(path, target, 0);
    return res;

    function backtrack(path, target, start) {
        if (target === 0) {
            res.push(path);
            return;
        }

        for (var i = start; i < len; i++) {
            if (target < candidates[i]) continue;
            if ((i > start) && (candidates[i-1] === candidates[i])) continue;
            path.push(candidates[i]);
            backtrack(path.slice(), target - candidates[i], i + 1);
            path.pop();
        }
    }
};
```