### 解题思路
参考了一下扣友的代码，重新理了下思路，写了写每句代码的意思

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var massage = function(nums) {
    if (nums.length === 0) return 0;

    // 假如数组长度1
    let selMax_y = nums[0]; // 假如选择当前预约的最大值
    let selMax_n = 0; // 假如未选择当前预约的最大值
    // 数组长度大于1 对于每个值只有选或不选两种情况
    for(let i = 1; i < nums.length; i++){
        // 暂存 未选择当前预约的最大值
        let val = selMax_n;

        // 情况一 ：不选择当前预约时的最大值
        // 此时最大值肯定是之前选和不选中较大的那个
        selMax_n = Math.max(val,selMax_y);
        
        // 情况二 ：选择当前预约时的最大值
        // 此时最大值肯定之前选中最大值(也就是未选择该预约时最大值)加上当前值
        selMax_y = val + nums[i];
        
    }
    // 肯定返回俩最大值里比较大的那个啦
    return Math.max(selMax_y,selMax_n)
};
```