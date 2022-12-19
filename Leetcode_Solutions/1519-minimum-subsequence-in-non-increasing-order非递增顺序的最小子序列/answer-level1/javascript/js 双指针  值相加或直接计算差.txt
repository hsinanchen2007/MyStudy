###### 根据题目，先排序，方便拿出满足条件的最大的子序列；后面的和大于前面的和
```
// 时间O(N) 空间O(1)
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var minSubsequence0 = function(nums) {
    nums.sort((a,b) => {return a-b})
    let start = 0, end = nums.length - 1, sonArr = [], leftSum = rightSum = 0
    while(start <= end){
        if(leftSum + nums[end] >= rightSum){
            sonArr.push(nums[end])
            rightSum += nums[end]
            end--
        }else{
            leftSum += nums[start]
            start++
        }
        // console.log(start, end, leftSum, rightSum)
    }
    return sonArr
};

// 缩减一个变量  但是根据leetcode反馈，时间加长了
var minSubsequence1 = function(nums) {
    nums.sort((a,b) => {return a-b})
    let start = 0, end = nums.length - 1, sonArr = [], dif = 0
    while(start <= end){
        if(dif <= nums[end]){
            sonArr.push(nums[end])
            dif += nums[end]
            end--
        }else{
            dif -= nums[start]
            start++
        }
    }
    return sonArr
};
```
