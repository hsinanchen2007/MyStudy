### 解题思路
没啥可说的

### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {boolean}
 */
var checkSubarraySum = function(nums, k) {
    for(let i = 0;i<nums.length;i++){
        let sum = nums[i]
        for(let n = i+1;n<nums.length;n++){
            sum = sum + nums[n]
                if(sum%k==0){
                return true
                }else if(k===0&&sum===0){

                return true
            }
        }
    }
    return false
};
```