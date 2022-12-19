### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var singleNumber = function(nums) {
    nums.sort((m, n) => {
        if(m < n) return -1
        else if (m > n) return 1
        else return 0
    })
    for(let i=0; i<nums.length; i+=2) {
        if(nums[i] !== nums[i+1]) {
            return nums[i]
            break
        }
    }
};
```