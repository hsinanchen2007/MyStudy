#### 思路一（splice）
删除数组中等于`val`的元素。
#### 代码
```
var removeElement = function(nums, val) {
    for (let i = 0; i < nums.length; i++) {
        if (nums[i] === val) {
            nums.splice(i, 1);
            i--;
        }
    }
    return nums.length;
};
```
#### 思路二（双指针）
定义指针`j`指向值不为`val`的元素位置。
#### 代码
```
var removeElement = function(nums, val) {
    let j = 0;
    for (let i = 0; i < nums.length; i++) {
        if (nums[i] !== val) {
            nums[j++] = nums[i];
        }
    }
    return j;
};
```