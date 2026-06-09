### 思路一

在范围 $0～n-1$ 内的 $n$ 个数字中有且只有一个数字不在该数组中，所以我们可以通过遍历来判断下标是否跟当前的值一致，如果不一致，那么返回当前下标，如果遍历完了还没有找到，那么最后返回 $n$

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var missingNumber = function(nums) {
    let i = 0
    while (i < nums.length) {
        if (i !== nums[i]) {
            return i
        }
        i++
    }
    return i
};
```

### 思路二

如果当前的数与下标对不上，那么说明左边一定缺失了数字，只有左边缺失了数字才会影响当前的数字。因此有两种情况：

- 如果 ``数组`` 的中位数跟下标相同，说明左半区的数字跟下标都对得上，缺失的数字在右半区
- 如果 ``数组`` 的中位数跟下标不同，说明缺失的数字在左半区

基于以上的结论，这道题我们可以用 ``二分法`` 来解决。

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var missingNumber = function(nums) {
    let lo = 0
    let hi = nums.length - 1
    while (lo <= hi) {
        let mid = Math.floor(lo + hi)
        if (nums[mid] === mid) {
            lo = mid + 1
        } else {
            hi = mid - 1
        }
    }
    return lo
};
```