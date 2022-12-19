**数组被按类别两边?** 这不就是快排的思想吗？而且还是一个子循环。
- base 保存首元素
```javascript
const base = nums[0];
```

- 然后就是快排了，只不过判断条件换一下
```javascript
// 快排的条件
while(left < right && nums[left] <= base) right--;
// 本题的条件
while(left < right && nums[right]%2 === 0) right--;
```
总的代码：
```JavaScript
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var exchange = function(nums) {
    if(nums.length === 0) return nums;
    let base = nums[0];
    let left = 0;
    let right = nums.length - 1;
    while(left < right){
        while(left < right && nums[right]%2 === 0) right--;
        if(left < right) {
            nums[left ++] = nums[right];
        }
        while(left < right && nums[left]%2 === 1) left++;
        if(left < right){
            nums[right --] = nums[left];
        }
    }
    nums[left] = base;
    return nums;
};
```
