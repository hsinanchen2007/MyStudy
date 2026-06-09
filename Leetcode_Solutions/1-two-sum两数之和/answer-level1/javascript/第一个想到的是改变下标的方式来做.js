### 解题思路
只是简单的实现，没有考虑内存消耗和时间复杂度空间复杂度

### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    let len = nums.length - 1, m=0, n=1;

    while(m < len || n < len){
        if(nums[m] + nums[n] == target){
            return [m, n]
        }else{
            if(n < len){
                n++;
            }else if(m < len){
                m++;
                n=m+1;
            }
        }
    }
    console.log("无法找到匹配");
};
```