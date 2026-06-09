### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    let arrMap = new Map()
    for(let i=0; i< nums.length; i++){
        let key = target - nums[i]
        
        if(arrMap.has(key)){
            return [arrMap.get(key),i]
        }
        arrMap.set(nums[i],i)
    }
};

twoSum([2,7,11,15],9)
```