var findNumberOfLIS = function(nums) {
    // 用两个数组存
    let length_dp = new Array(nums.length).fill(1),
        count_dp = new Array(nums.length).fill(1)

        if (nums.length <= 1) return nums.length

    for(let i = 0; i < nums.length; i++) {
        for(let j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
                // 后面大于前面可能是最大连续数组
                if (length_dp[i] <= length_dp[j]) {
                    //初始化的情况/前面的j所在的最长子序列大于之前存储的某个最长子序列的情况要被替换掉
                    length_dp[i] = length_dp[j] + 1
                    count_dp[i] = count_dp[j]
                }else if (length_dp[i] == length_dp[j] + 1){
                    // 说明加上这个数再是最长子序列
                    count_dp[i] += count_dp[j]
                }
            }
        }
    }
    let max = Math.max(...length_dp)
    let sum = 0

    for(let i = 0; i < count_dp.length; i++) {
        if (length_dp[i] == max) {
            sum += count_dp[i]
        }
    }

    return sum
};