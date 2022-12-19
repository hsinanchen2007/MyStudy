### 解题思路
一次遍历，当累加的元素数量小于等于k时(i<k)，直接累加，并且max=sum
当累加的元素数量大于k时(i>=k)),累加当前元素，并删除第i-k个元素，然后max取sum和之前值较大的一个

### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var findMaxAverage = function(nums, k) {
    let max = 0 , sum = 0
    for(let i = 0;i<nums.length;i++){
        if(i<k){
            sum+=nums[i]
            max = sum
        }else{
            sum+=nums[i]
            sum-=nums[i-k]
            max = Math.max(max,sum)
        }
    }
    return max/k
};
```