### 解题思路
双指针法，准备两个游标p、q,q每次循环加1，p遇到不同元素时加1，数组长度即为p+1的值

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */

var removeDuplicates = function (nums) {
    let p = 0, q = 1;
    while (q < nums.length) {
        if(nums[p]!=nums[q]){
           nums[p + 1] = nums[q]
           p++;
        }
        q++;
    }
    return p+1;
};

```