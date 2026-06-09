### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} candidates
 * @param {number} target
 * @return {number[][]}
 */
var combinationSum = function(candidates, target) {
    let n = candidates.length;
    let res = [];
    let path = [];

    candidates = candidates.sort((a,b) => a - b)
    backtrack(path, target, 0);
    return res;


    function backtrack(path, target, start) {
        console.log(path, target, start)
        if ( target == 0){
            res.push(path);
            return;
        }

        for (let i = start; i < n; i++) {
            if(target < candidates[i]) break;

            path.push(candidates[i]);
            backtrack(path.slice(), target - candidates[i], i);
            path.pop();
        }
    }

}

```