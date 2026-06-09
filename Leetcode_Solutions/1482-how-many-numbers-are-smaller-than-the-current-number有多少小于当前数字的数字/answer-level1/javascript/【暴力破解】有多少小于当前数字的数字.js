### 解题思路
时间复杂度O(n^2)

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var smallerNumbersThanCurrent = function(nums) {
    let r=[]
    for(let i=0;i<nums.length;i++){
        let count=0;
        for(let l=0;l<nums.length;l++){
            if(nums[l]<nums[i]) count++;
        }
        r.push(count)
    }
    return r
};
```