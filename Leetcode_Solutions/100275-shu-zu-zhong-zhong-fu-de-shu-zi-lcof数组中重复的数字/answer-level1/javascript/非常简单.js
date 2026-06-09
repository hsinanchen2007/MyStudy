### 解题思路
![image.png](https://pic.leetcode-cn.com/bf360a6b14cdb3c49083e484f5c77c07534852983cd8fabda2053a0c72e1dce1-image.png)
利用计数排序的思想
- 先求出数组的最大值和最小值之差
- 然后开辟一个差值长度 + 1的辅助数组，每一位都为0
- 遍历数组nums，每一位减去最小值就是该值在辅助数组中的位置，让此位置++
    - 遍历的过程中判断辅助数组该位置的值是否大于1，如果大于1说明该数字出现过
    - 直接返回该位置+最小值即为所求
- 如果遍历完数组nums也没找到大于1的位置，即没有重复的数，返回-1即可。

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var findRepeatNumber = function(nums) {
    //计数排序思想
    let min = nums[0], max = nums[0];
    let len = nums.length;
    for(let i = 1; i < len; i ++) {
        if(nums[i] > max) max = nums[i];
        if(nums[i] < min) min = nums[i];
    }
    let difVal = max - min;
    let assistArr = new Array(difVal + 1).fill(0);
    for(let i = 0; i < len; i ++) {
        let number = nums[i] - min;
        assistArr[number] ++;
        if(assistArr[number] > 1) return number + min;
    }
    return -1;
};
```