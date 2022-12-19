### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var missingNumber = function (nums) {
    if (nums.length === 0) return 0;
    let len = nums.length - 1;
    let l = 0;
    let r = len;
    while (l < r) {
        let mid = l + r >> 1;
        //二分的规律，索引值不等于当前值，前半部分满足索引值等于值，后半部分不满足
        if (nums[mid] != mid) r = mid;
        else l = mid + 1;
    }
    //特判一下，真个区间都是满足的一一对应的，那么缺失的数应该是下一个数
    if (nums[r] == r) r++;
    return r;
};
```