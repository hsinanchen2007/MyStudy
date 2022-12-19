### 解题思路
1.定义一个map字典用来存储，差值为key，当前数组项为value
2.遍历数组，判断数组的项是否在map字典项内
3.如果有，返回当前数组下标和map字典值

### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    const map = {}
    
    for(let i = 0;i < nums.length;i ++) {
        const diff = target - nums[i]
        
        if(map.hasOwnProperty(nums[i])) {
           return [nums.indexOf(diff), i]
        }else {
            map[diff] = nums[i]
        }
    }

    return []
};
```