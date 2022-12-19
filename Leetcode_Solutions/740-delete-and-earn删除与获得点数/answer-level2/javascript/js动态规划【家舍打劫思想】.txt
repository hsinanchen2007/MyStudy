/**
 * @param {number[]} nums
 * @return {number}
 */
var deleteAndEarn = function(nums) {
    // 重新构建一个数组
    // 家舍打劫
    // js遇到需要计数的情况可以将数组的下标与之相对应，相当于是一个map
    // 转换成新的数组之后，就表示：每个数组的位置表示nums中的数字有多少个，下标表示nums中的数字，其中乡邻的家舍【数字】不能偷
    // 如果要偷当前的家舍就是新数组对应的下标 * 新数组的本身的数字
    if(nums.length == 0) return 0
    let len = Math.max(...nums) + 1
    let new_nums = new Array(len).fill(0)
    nums.filter(item => new_nums[item]++)
    let dp = []

    dp[1] = new_nums[1] * 1
    dp[2] = Math.max(new_nums[2] * 2, dp[1])

    for(let i = 3; i < new_nums.length; i++) {
        dp[i] = Math.max(dp[i - 1], dp[i - 2] + new_nums[i] * i)
    }

    console.log(dp)
    return dp[new_nums.length - 1]
};