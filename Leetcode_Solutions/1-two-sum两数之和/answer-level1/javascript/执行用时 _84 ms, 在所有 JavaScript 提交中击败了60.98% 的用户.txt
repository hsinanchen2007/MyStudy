### 解题思路
用一个对象保存nums的键和值，对象的键是nums的值，对象的值是nums的键，即：
nums = [2, 7, 11, 15]
obj = ['2': 0, '7': 1, '11': 2, '15': 3]

### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    let obj = {}
    for(let i=0; i<nums.length; i++){
        obj[nums[i]] = i
    }
    console.log(obj)
    for(let i=0; i<nums.length; i++){
        const diff = target - nums[i]
        if(obj.hasOwnProperty(diff) && (obj[diff] != i)){  //如果obj含有nums[i]这个键，并且对应的值(即nums的键) 不等于i，就是正确结果
            return [i, obj[diff]]
        }
    }
};
```