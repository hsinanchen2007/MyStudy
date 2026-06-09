// ## 485.最大连续1的个数

// ### 原题

// 给定一个二进制数组， 计算其中最大连续1的个数。

// 示例 1:

// ```
输入: [1,1,0,1,1,1]
输出: 3
解释: 开头的两位和最后的三位都是连续1，所以最大连续1的个数是 3.
// ```

// 注意：

// - 输入的数组只包含 0 和1。
// - 输入数组的长度是正整数，且不超过 10,000。


// ### 思路

// ![1.png](https://pic.leetcode-cn.com/3fe655f5a1e832a75f7491c78a7a6c4996e7b21fc4eca1ace9b8f70869e2b3ec-file_1569216121863)

// ### 代码

// #### 思路一

// ```js

/**
 * @param {number[]} nums
 * @return {number}
 */
var findMaxConsecutiveOnes = function(nums) {
    const dp = []
    
    for (let i = 0; i < nums.length; i++) {
        if (nums[i] & 1) {
            dp[i] = dp[i - 1] === undefined ? 0 + 1 : dp[i - 1] + 1
        } else {
            dp[i] = 0
        }
    }
    
    return Math.max(...dp)
};
// ```

// #### 思路二

// ```js

/**
 * @param {number[]} nums
 * @return {number}
 */
var findMaxConsecutiveOnes = function(nums) {
    let max_length = 0
    let temp = 0
    
    for (let i = 0; i < nums.length; i++) {
        if (nums[i] & 1) {
            temp += 1
        } else {
            temp = 0
        }
        max_length = Math.max(max_length, temp)
    }
    
    return max_length
};
// ```

// ## 487.最大连续1的个数 II

// ### 原题

// 给定一个二进制数组，你可以最多将 1 个 0 翻转为 1，找出其中最大连续 1 的个数。

// 示例 1：

// ```
输入：[1,0,1,1,0]
输出：4
解释：翻转第一个 0 可以得到最长的连续 1。
     当翻转以后，最大连续 1 的个数为 4。
 
// ```

// 注：

// - 输入数组只包含 0 和 1.
// - 输入数组的长度为正整数，且不超过 10,000
//  


// ### 思路

// ![2.png](https://pic.leetcode-cn.com/f3d837e508b313bd6ade6f08904e130494dd7d4a0c32c82dfde57cb72d9b3ddd-file_1569216121869)

// 我们需要两个数组记录状态，`dp1`记录不进行任何翻转的状态，`dp2`记录遇到`0`就进行翻转的状态。

// 题目规定我们只可以进行**一**次翻转。所以在`dp2`中，如果遇到0时，我们**不能**借助`dp2`数组中的前一个状态，获取当前的状态。因为之前可能已经经过多次的翻转。

// 但是`dp1`中是没有经过任何翻转的，所以在`dp2`中遇到0，我们可以使用`dp1`的前一个状态的值加上1（翻转当前的0），获取当前的状态。

// 最后返回`dp2`中的最大值即可。

// 举一个例子🌰

// ```js

nums = [1,0,1,1,0,1]

dp1 = [ 1, 0, 1, 2, 0, 1 ]

// 如果nums[1]转1，dp2[1] = 2
// dp2[2] = 3
// dp2[3] = 4
// 如果nums[4]转1，dp2[4] = dp1[3] + 1 = 3
// dp[5] = 4
dp2 = [ 1, 2, 3, 4, 3, 4 ]
// ```

// ### 代码

// ```js

/**
 * @param {number[]} nums
 * @return {number}
 */
var findMaxConsecutiveOnes = function(nums) {
   const dp1 = []
   const dp2 = []
   
   for (let i = 0; i < nums.length; i++) {
       if (nums[i] & 1) {
           dp1[i] = dp1[i - 1] === undefined ? 0 + 1 : dp1[i - 1] + 1
           dp2[i] = dp2[i - 1] === undefined ? 0 + 1 : dp2[i - 1] + 1
       } else {
           dp1[i] = 0
           dp2[i] = dp1[i - 1] === undefined ? 0 + 1 : dp1[i - 1] + 1
       }
   }
    
   return Math.max(...dp2)
};
// ```

// ## 1004.最大连续1的个数 III

// ### 原题

// 给定一个由若干 0 和 1 组成的数组 A，我们最多可以将 K 个值从 0 变成 1 。

// 返回仅包含 1 的最长（连续）子数组的长度。

//  

// 示例 1：

// ```
输入：A = [1,1,1,0,0,0,1,1,1,1,0], K = 2
输出：6
解释： 
[1,1,1,0,0,1,1,1,1,1,1]
粗体数字从 0 翻转到 1，最长的子数组长度为 6。
// ```

// 示例 2：

// ```
输入：A = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], K = 3
输出：10
解释：
[0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
粗体数字从 0 翻转到 1，最长的子数组长度为 10。
// ```

// ### 思路

// 本题使用双指针的思路解决。

// `start`和`end`指针初始的时候都是指向0，并使用一个额外的变量记录最大值。

// `end`指针向后移动，遇到0时，统一转为1，`K`自减1，并记录此时最大值。

// 当`end`指针指向0并且`K`自减到0时，此时我们需要向前移动`start`指针：
// - 如果`nums[start] == 1`, 我们需要直接跳过，因为此时我们不能给`K`加一，最大值不会有任何变化。
// - 如果`nums[start] == 0`，我们在跳过它之后，可以给`K`加一（因为少了一个0）。我们`end`指针可以继续向后移动。直到末尾。

// ### 代码

// ```js

/**
 * @param {number[]} A
 * @param {number} K
 * @return {number}
 */
var longestOnes = function(A, K) {
    let max_length = 0
    let temp = 0
    let startIndex = 0
    let endIndex = 0
    
    while (endIndex < A.length) {
        if (A[endIndex] & 1) {
            temp += 1
            endIndex += 1
        } else {
            if (K > 0) {
                temp += 1
                K -= 1
                endIndex += 1
            } else {
                if (A[startIndex] & 1) {
                    let on_off = true
                    while (on_off && startIndex <= endIndex) {
                        if (A[startIndex] === 0) {
                            on_off = false
                        }
                        startIndex += 1
                        temp -= 1
                    }
                } else {
                    startIndex += 1
                    temp -= 1
                }
                K += 1
            }
        }
        max_length = Math.max(max_length, temp)
    }
    
    return max_length
};
// ```

