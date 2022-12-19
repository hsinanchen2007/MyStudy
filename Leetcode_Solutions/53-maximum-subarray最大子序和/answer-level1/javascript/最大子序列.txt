### 解题思路

动态规划，丢弃无用的和

### 代码

```javascript
/**
 * 抄的题解的，添加了输出最大子序列的功能。思考了挺久才理解
 * @param {number[]} nums
 * @return {number}
 */
var maxSubArray = function (nums) {
    let ans = nums[0];
    let sum = 0;
    let l_offset = 0;
    let r_offset = 0;

    for (let i = 0; i < nums.length; i++) {
        const num = nums[i];

        if (sum > 0) {
            sum += num;
        } else {
            /**  */
            console.log(sum, "=", num, i);
            l_offset = i;
            sum = num;
        }
        if (sum > ans) {
            console.log(sum, i);
            r_offset = i;
            ans = sum;
        }
    }

    console.log(
        l_offset,
        r_offset,
        nums.slice(l_offset, r_offset + 1),
        // nums.slice(l_offset, r_offset + 1).reduce((p, c) => p + c),
    );

    return ans;
};
// 超慢的
// var maxSubArray = function (nums) {
//     let max = -Infinity
//     for (let sub_legnth = 1; sub_legnth <= nums.length; sub_legnth++) {
//         for (let i =0; i< nums.length-sub_legnth; i++) {
//             let sum = 0
//             for (let k = i; k < i+sub_legnth; k++) {
//                 sum += nums[k]
//             }
//             if (sum > max) max = sum
//         }
//     }
//     return max
// };
```