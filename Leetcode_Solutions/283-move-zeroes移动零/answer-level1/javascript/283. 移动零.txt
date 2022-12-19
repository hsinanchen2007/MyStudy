### 解题思路

- 定义两个变量：``i`` 指向当前数字的 ``下标``，另外一个变量 ``left`` 指向 ``非零数字`` 的下标
- 如果当前数字为 ``非零数字``，那么两个变量同时自增
- 如果当前数字为 $0$，``i`` 自增，``left`` 不变
- 如果遍历结束， $left < nums.length$，那么说明需要补 $0$，这时候直接将 $left <= i < nums.length$ 范围内的数组填充 $0$ 即可，否则直接结束。

⚠️小技巧：数组 ``nums`` 的长度最好先保存下来，避免多次获取。

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var moveZeroes = function(nums) {
    let i = 0
    let left = 0
    let len = nums.length
    
    while (i < len) {
        if (nums[i] !== 0) {
            nums[left++] = nums[i]
        }
        i++
    }
    while (left < len) {
        nums[left++] = 0
    }
};

```
- 时间复杂度：$O(n)$
- 空间复杂度：$O(1)$