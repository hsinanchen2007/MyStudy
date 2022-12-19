### 解题思路
双指针法：
定义快慢指针，遍历数组，快指针移动，慢指针位置的数据与快指针位置的数据不等时，慢指针移动，将快指针位置的数据赋值到慢指针位置(快指针移动时，慢指针位置数据与快指针位置数据相等时，代表快指针位置的数据在重复，此时不作任何处理，慢指针停留)。
注：函数执行完之后，原数组的长度并没有改变，只是将未重复数据都挪到了前面，后面任然保留原数组后面k位数据(k为重复数据的个数)。

复杂度分析：
时间复杂度： O(n)。 遍历原数组n次(n为数组长度)(一个for循环)。
空间复杂度： O(1)。 未使用额外线性表空间,只使用常数个非线性表空间。

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var removeDuplicates = function(nums) {
    const len = nums && nums.length
    let quick = 1
    let slow = 0
    for (; quick < len; quick++) {
        if (nums[slow] !== nums[quick]) {
            slow++
            nums[slow] = nums[quick]
        }
    }
    return slow + 1
};
```