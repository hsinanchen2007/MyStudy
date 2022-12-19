### 回溯算法系列
- [39:组合总和](https://leetcode-cn.com/problems/combination-sum/solution/zu-he-zong-he-by-fanzhanxiang/)
- [40:组合总和II](https://leetcode-cn.com/problems/combination-sum-ii/solution/zu-he-zong-he-ii-by-fanzhanxiang/)
- [46: 全排列](https://leetcode-cn.com/problems/permutations/solution/quan-pai-lie-by-fanzhanxiang/)
- [47: 全排列II](https://leetcode-cn.com/problems/permutations-ii/solution/quan-pai-lie-ii-by-fanzhanxiang/)
- [77: 组合](https://leetcode-cn.com/problems/combinations/solution/zu-he-by-fanzhanxiang/)
- [78: 子集](https://leetcode-cn.com/problems/subsets/solution/zi-ji-by-fanzhanxiang/)
- [90: 子集II](https://leetcode-cn.com/problems/subsets-ii/solution/zi-ji-ii-by-fanzhanxiang/)
#### 一、排序后上一个元素和下一个元素对比
```javascript
/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var subsetsWithDup = function(nums) {
    let ans = [];
    let path = [];
    nums.sort((a,b) => a-b)
    dfs(ans,path,0,nums)
    return ans;
};
const dfs = function(ans,path,start,nums) {
    if(path.length > nums.length) return;
    ans.push(path);
    for(let i = start; i < nums.length; i++) {
        if (i > start && nums[i] === nums[i-1]) continue;
        path.push(nums[i]);
        dfs(ans,path.slice(),i+1,nums);
        path.pop()
    }
}
```
#### 二、利用哈希表

```javascript
/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var subsetsWithDup = function(nums) {
    let ans = [];
    let path = [];
    nums.sort((a,b) => a-b)
    dfs(ans,path,0,nums)
    return ans;
};
const dfs = function(ans,path,start,nums) {
    if(path.length > nums.length) return;
    ans.push(path);
    let map = new Map();
    for(let i = start; i < nums.length; i++) {
       if(!map.get(nums[i])) {
           map.set(nums[i],true);
           path.push(nums[i]);
           dfs(ans,path.slice(),i+1,nums);
           path.pop()
       }
    }
}
```