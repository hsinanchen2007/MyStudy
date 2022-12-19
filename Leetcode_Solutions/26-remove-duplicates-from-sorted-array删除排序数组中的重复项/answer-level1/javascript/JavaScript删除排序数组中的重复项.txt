#### 思路一：
遍历nums，如果下一个值和当前值相等，则删除下一个数。
#### 代码
```
var removeDuplicates = function(nums) {
    for (let i = 0; i < nums.length - 1; i++) {
        if (nums[i] === nums[i + 1]) {
            nums.splice(i+1, 1);
            // 重置下标，继续从当前位置判断
            i--;
        }
    }
    return nums.length;
};
```
#### 思路二（双指针）：
指针i遍历nums，指针j从1开始指向不重复数的位置，如果```nums[i] !== nums[i-1]```，则```nums[j] = nums[i]```。
#### 代码
```
var removeDuplicates = function(nums) {
    let j = 1;
    for (let i = 1; i < nums.length; i++) {
        if (nums[i] !== nums[i - 1]) {
            nums[j++] = nums[i];
        }
    }
    nums.length = j;
    return j;
};
```

