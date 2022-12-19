#### 思路一
取出最后一个数，然后在数组头部插入该数即可。
#### 代码
```
var rotate = function(nums, k) {
    let i = 0;
    k %= nums.length;
    while (i++ < k) {
        nums.splice(0, 0, nums.pop());
    }
};
```
#### 思路二
用一个数组，按正确的顺序保存元素，再赋值给nums。
#### 代码
```
var rotate = function(nums, k) {
    let temp = []
    k %= nums.length;
    for (let i = 0; i < nums.length; i++) {
        temp[(i + k) % nums.length] = nums[i];
    }
    nums.splice(0, nums.length, ...temp);
};
```
#### 思路三（三次旋转）
1. 原始数组：`[1,2,3,4,5,6,7]`；
2. 第一次旋转：旋转整个数组：`[7,6,5,4,3,2,1]`；
3. 第二次旋转：旋转前k个数：`[5,6,7,4,3,2,1]`；
4. 第三次旋转：旋转k到末尾的数：`[5,6,7,1,2,3,4]`；
#### 代码
```
var rotate = function(nums, k) {
    k %= nums.length;
    reverse(nums, 0, nums.length - 1);
    reverse(nums, 0, k - 1);
    reverse(nums, k, nums.length - 1);

    function reverse(nums, start, end) {
        while (start < end) {
            let temp = nums[end];
            nums[end] = nums[start];
            nums[start] = temp;
            start++;
            end--;
        }
    }
};
```




