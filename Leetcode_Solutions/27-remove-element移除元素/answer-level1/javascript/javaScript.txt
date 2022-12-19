### 解题思路
其实最重要的是这个 i--; 遍历数组如果有和val相同的值就用splice方法删除该项，删除后因为原数组少了一位，所以得回退一位

### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} val
 * @return {number}
 */
var removeElement = function(nums, val) {
    for(let i=0;i<nums.length;i++){
        if(nums[i] == val){
            nums.splice(i,1);
            i--;
        }
    }
    return nums.length;
};
```