### 解题思路
我调库我光荣(手动狗头)

### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var findKthLargest = function(nums, k) {
    let arr=nums.sort((a,b)=>b-a);
    return arr[k-1]
};
```