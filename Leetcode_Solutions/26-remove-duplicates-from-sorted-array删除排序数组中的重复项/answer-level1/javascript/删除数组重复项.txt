### 解题思路
  在原数组基础上 想到的就是按照下标一步一步往后挪做比较
### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var removeDuplicates = function (nums) {
    let len = 0; //相当于清除数组 重新复制
    for (let i = 0; i < nums.length; i++) {
        if (nums[i] != nums[i + 1]) {
            nums[len++] = nums[i] // 不存在重复 结果为true 把值赋给下标为len的nums[len++] 
        }
    }
    return len 
```