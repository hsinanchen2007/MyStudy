### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var exchange = function (nums) {
    // 类似快排，双指针
    let l = -1;
    let r = nums.length;
    let res = [];//保存答案
    while (l < r) {
        do l++; while (nums[l] % 2 == 1)//只要左半边是奇数就后移
        do r--; while (nums[r] % 2 == 0)//只要右半边是奇数就前移
        // 交换位置
        if (l < r) [nums[r], nums[l]] = [nums[l], nums[r]];
        //nums[l] = [nums[r], nums[r] = nums[l]][0];
    }
    return nums;
};
```