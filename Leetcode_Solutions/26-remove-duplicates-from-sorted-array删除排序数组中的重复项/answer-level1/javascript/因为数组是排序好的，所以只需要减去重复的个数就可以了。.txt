### 解题思路
因为数组是排序好的，所以只需要减去重复的个数就可以了。
count是计算重复的个数的。

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var removeDuplicates = function(nums) {
    let n = nums.length;
    let count = 0;
    for(let i=1;i<n;i++){
        if(nums[i]!=nums[i-1]){
            nums[i-count] = nums[i]
        }else{
            count++
        }
    }
    return n-count
};
```