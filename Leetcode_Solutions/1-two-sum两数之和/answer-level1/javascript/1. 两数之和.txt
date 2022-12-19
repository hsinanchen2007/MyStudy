### 解题思路
主要思路是通过差值来寻找。
1.用while循环从后往前遍历。
2.每次遍历先pop最后一个值，再通过indexOf来查找是否有对应的差，pop的好处是为了防止两个数相等。
3.如果有对应的值，索引就是indexOf和数组的长度。

### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
   let i = nums.length;
    while(i > 1) {
        let last = nums.pop();
        if (nums.indexOf(target - last) > -1) {
            return [nums.indexOf(target - last), nums.length]
        }
        i--
    }
};
```