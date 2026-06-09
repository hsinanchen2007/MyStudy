- 两次遍历
    1. 第一次: 通过交换, 将所有数字放在本应该在的位置, 这时只有重复的元素待在了缺失元素的位置上
    2. 第二次: 遍历找出重复的元素

```javascript 
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var findDuplicates = function(nums) {
    let res = [];
    
    for (let i = 0; i < nums.length; i++) {
        let temp = nums[i];
        while (i !== temp - 1 && nums[temp - 1] !== temp) {
            // Exchange nums[i] and nums[temp - 1]
            nums[i] = nums[temp - 1];
            nums[temp - 1] = temp;
            temp = nums[i];
        }
    }

    nums.forEach(function(num, id) {
        if (num !== id + 1) res.push(num);
    });
    
    return res;
};
```

**Github**: <https://github.com/lucaschang95/>

