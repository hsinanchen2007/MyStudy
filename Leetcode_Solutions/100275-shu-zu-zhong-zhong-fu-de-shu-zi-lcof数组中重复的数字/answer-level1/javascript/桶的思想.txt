### 解题思路
把对应的元素 ,放在对应的下标上

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var findRepeatNumber = function(nums) {
    if(nums.length == 0) return null;
    let res = null;
    for(let i = 0 ; i < nums.length ; i ++) {
        if(nums[i] !== i) {
            if(nums[i] == nums[nums[i]]) {
                res = nums[i];
                break;
            };
            //交换
            let temp = nums[nums[i]];
            nums[nums[i]] = nums[i];
            nums[i] = temp;
        }
    }
    return res;
};
```