### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var lengthOfLIS = function(nums) {
    let count = [1];
    if(nums.length == 0){
        return 0;
    }
    for(let i = 1; i < nums.length; i++){
        let res = 1;
        for(let j = 0; j < i; j++){
            if(nums[i] > nums[j]){
                res = Math.max(res, count[j] + 1)
            }
        }
        count[i] = res;
    }
    return Math.max(... count);
};
```