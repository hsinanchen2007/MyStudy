### 解题思路
查找数，思路就要往Map上想，此题的核心是，只遍历一遍，一边判断，一边将值放进去，因为只要有合适的，就能匹配上

### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    let tempDict = {}
    for(let i =0; i< nums.length; i++){
        let tempValue = target - nums[i];
        if(tempDict[tempValue] !=null){
            return [tempDict[tempValue] , i]
        }
        tempDict[nums[i]] = i
    }
};
```