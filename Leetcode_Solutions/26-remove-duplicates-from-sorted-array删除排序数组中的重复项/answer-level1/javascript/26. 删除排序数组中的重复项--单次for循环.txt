### 执行结果
![image.png](https://pic.leetcode-cn.com/b3b769d40aff03b5239ed8fcc9be7cd54945f328da3fd3eebe8f86da98198656-image.png)

### 解题思路
关键点在于：
1. 设置一个指针 slow ，指向第一个不重复数字的位置。
2. 设置另一个指针 i 不断向后取值，一旦发现不重复数字就与将第一个指针向前移动一位，并将新发现的不重复数字覆盖在第一个指针 slow 当前所处位置。

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var removeDuplicates = function(nums) {
    let slow = 0;
    let len = nums.length;
    for (let i = 1; i < len; i++) {
        if (nums[slow] != nums[i]) {
            slow++
            nums[slow] = nums[i]
        }
    }
    return slow + 1
};
```