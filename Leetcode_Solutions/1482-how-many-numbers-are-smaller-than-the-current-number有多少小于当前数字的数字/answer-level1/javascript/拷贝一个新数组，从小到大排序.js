### 解题思路
深拷贝一个新数组，sort会改变原数组的顺序，注意！
新数组从小到大排序，循环旧数组中各项在新数组的第一次出现位置的index，push进接收的数组

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var smallerNumbersThanCurrent = function(nums) {
    let newNums = [...nums];
    newNums.sort((a, b) => a - b);
    let count = [];
    for(i=0;i<nums.length;i++) {
        count.push(newNums.indexOf(nums[i]));
    }
    return count
};
```