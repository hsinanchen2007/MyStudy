### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var findRepeatNumber = function(nums) {
    //利用set的特性
    const s = new Set();
    for(let i = 0,len=nums.length-1;i<=len;i++){
        if(s.has(nums[i])){
            return nums[i]
        }
        s.add(nums[i])
    }

    return -1;
};
```