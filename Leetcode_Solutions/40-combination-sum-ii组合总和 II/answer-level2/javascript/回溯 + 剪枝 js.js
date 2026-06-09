![图片.png](https://pic.leetcode-cn.com/eceb1b1d69f0b7eb84b427433bbab03e72de0f9fc1cc1146b2c6f47cca0d62cc-%E5%9B%BE%E7%89%87.png)
题目的关键是如何如何剪枝
```
/**
 * @param {number[]} candidates
 * @param {number} target
 * @return {number[][]}
 */
var generateCombination = function (candidates, target, cur, res, lastindex) {
    if (target === 0) {
        res.push([].concat(cur))
        return
    }
    if (target < 0 || lastindex == candidates.length) {
        return
    }
    for(let i=lastindex; i< candidates.length; i++) {
        cur.push(candidates[i])
        if(i > lastindex && candidates[i] === candidates[i - 1]){
            cur.pop()
            continue
        }
        generateCombination(candidates, target-candidates[i], cur, res, i+1)        
        cur.pop()
    }
}

var combinationSum2 = function(candidates, target) {
    candidates.sort((a,b) => a - b)
    let cur = [], res = []
    generateCombination(candidates, target, cur, res, 0)
    return res
};
```
