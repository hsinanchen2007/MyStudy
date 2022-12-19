### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var findRepeatNumber = function(nums) {
    var s = new Set()
    let l = nums.length
    for(let i=0;i<l;i++){
        if(s.has(nums[i])){
            return nums[i]
        }
        else{
            s.add(nums[i])
        }
    }
};
```