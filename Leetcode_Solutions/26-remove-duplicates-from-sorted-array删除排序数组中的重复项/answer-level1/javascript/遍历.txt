### 解题思路
遍历数组，若当前元素的值跟上一个值相同，移除元素。因为移除了一个元素，所以index保持不变，则是取的下一个元素。
若当前元素值跟上一个不同，记录当前的值 index+1。继续下一个值的比较 直到index 等于 数组的长度-1表示所有元素遍历完毕

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var removeDuplicates = function(nums) {
    let i = 0;
    let lastValue = undefined;
    while(i < nums.length) {
        // 如果跟上次的值相同，删除数组元素 i保持不变
        if (lastValue === nums[i]) {
            nums.splice(i, 1);
        } else {
            // 跟上次的值不同，记录当前值 index+1
            lastValue = nums[i];
            i++;
        }
    }
    return nums.length;
};
```