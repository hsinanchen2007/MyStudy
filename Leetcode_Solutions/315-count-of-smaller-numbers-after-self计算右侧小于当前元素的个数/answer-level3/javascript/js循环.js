/*
 * @lc app=leetcode.cn id=315 lang=javascript
 *
 * [315] 计算右侧小于当前元素的个数
 */

// @lc code=start
/**
 * @param {number[]} nums
 * @return {number[]}
 */

var countSmaller = function(nums) {
    for(let i = 0;i<nums.length;i++){
        let a = 0;
        for(let j = i+1;j<nums.length;j++){
            if(nums[j]<nums[i]){
                a++;
            }
        }
        nums[i] = a;
    }
    return nums
};
// @lc code=end
