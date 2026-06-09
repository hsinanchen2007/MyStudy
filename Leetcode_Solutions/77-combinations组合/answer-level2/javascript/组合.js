### 回溯算法系列
- [39:组合总和](https://leetcode-cn.com/problems/combination-sum/solution/zu-he-zong-he-by-fanzhanxiang/)
- [40:组合总和II](https://leetcode-cn.com/problems/combination-sum-ii/solution/zu-he-zong-he-ii-by-fanzhanxiang/)
- [46: 全排列](https://leetcode-cn.com/problems/permutations/solution/quan-pai-lie-by-fanzhanxiang/)
- [47: 全排列II](https://leetcode-cn.com/problems/permutations-ii/solution/quan-pai-lie-ii-by-fanzhanxiang/)
- [77: 组合](https://leetcode-cn.com/problems/combinations/solution/zu-he-by-fanzhanxiang/)
- [78: 子集](https://leetcode-cn.com/problems/subsets/solution/zi-ji-by-fanzhanxiang/)
- [90: 子集II](https://leetcode-cn.com/problems/subsets-ii/solution/zi-ji-ii-by-fanzhanxiang/)
```javascript
/**
 * @param {number} n
 * @param {number} k
 * @return {number[][]}
 */
/**
 * @param {number} n
 * @param {number} k
 * @return {number[][]}
 */
function dfs(start, path, n, k, ans) {
    if (path.length === k) {
        ans.push(path);
        return;
    }
    for (let i = start; i <= n; i++) {
        path.push(i);
        dfs(i + 1, path.slice(), n, k, ans);
        path.pop();
    }
}
var combine = function (n, k) {
    let ans = [];
    dfs(1, [], n, k, ans);
    return ans;
};
```