### 解题思路
和快排分区思路的类似，left指针维护奇数区，right指针维护偶数区，从两端开始，指针相遇则停止。
![Snipaste_2020-03-16_20-39-50.png](https://pic.leetcode-cn.com/6a08a25c3d12d6089f92030ba6196f38736611b226c181df940648fb4e5430dd-Snipaste_2020-03-16_20-39-50.png)
### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var exchange = function (nums) {
    if (!nums.length) return nums
    let left = 0, right = nums.length - 1;
    while (left < right) {
        if (nums[left] & 1) {
            // 奇数则不操作
            left++
        } else {
            // 偶数则与右指针交换元素
            [nums[left], nums[right]] = [nums[right], nums[left]];
            right--
        }
    }
    return nums
};
```