### 解题思路
indexOf 比 findIndex 快贼多

### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */

var twoSum = function(nums, target) {
    let nums1 = [];
    // 创建差值数组
    for(let key in nums){
        nums1.push(target - nums[key]);
    }
    let keys = [];
    // 循环查差值
    for(let nowKey in nums){
        let focusKey = nums1.indexOf(nums[nowKey]);
        if(focusKey != -1&&nowKey != focusKey){
            keys = [nowKey, focusKey];
            break;
        }
    }
    return keys;
};
```