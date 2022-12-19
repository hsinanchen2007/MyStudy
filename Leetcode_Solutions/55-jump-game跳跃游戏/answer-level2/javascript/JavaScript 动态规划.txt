### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {boolean}
 */
var canJump = function(nums) {
    //如果只有一个,返回true
    if(nums.length === 1) return true;
    //记录所能到达的最大位置
    var res = nums[0];
    for(var i = 1; i < nums.length; i++){
        //如果最大位置不能到达当前位置，则跳出
        if(res < i) break;
        //如果最大位置超过最后一个位置，则返回true
        if(res >= nums.length - 1) return true;
        //计算能到达的最大位置
        res = res > nums[i] + i ? res : nums[i] + i;
    }
    return false;
};
```