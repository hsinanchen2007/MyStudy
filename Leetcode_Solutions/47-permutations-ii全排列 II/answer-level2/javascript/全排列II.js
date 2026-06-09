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
 * @param {number[]} nums
 * @return {number[][]}
 */
var permuteUnique = function(nums) {
    nums = nums.sort((a,b) => a - b);
    let ans = [];
    perm(0,nums,ans);
    return ans;
};
const perm = function(len,nums,ans) {
    if(len === nums.length ) {
        ans.push([...nums]);
        return;
    }
    let map = new Map();
    for(let i = len; i < nums.length; i++) {
        if(!map.get(nums[i])) {// 同层级中标记该元素是否已使用，未使用则进行替换
            map.set(nums[i], true);
            swap(nums,len,i);
            perm(len+1,nums,ans);
            swap(nums,len,i);
        }
    }
}
const swap = function(nums,l,r) {
    let temp = nums[l];
    nums[l] = nums[r];
    nums[r] = temp;
}
```