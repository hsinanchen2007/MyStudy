### 解题思路
抄作业成功

### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
// 第一次处理
function handleSums(nums, target, map, isTooMap = true){
    for(let key in nums){
        let diff = target - nums[key];    
        if(map.hasOwnProperty(diff)){
            return [ map[diff], key ];
        }else{
            map[nums[key]] = key;
        }
    }
}
var twoSum = function(nums, target) {
    let map = {};
    let keys = handleSums(nums, target, map);
    if(keys){
        return keys;
    }else{
        // 一个循环得不到正确结果 - 第二次循环
        return handleSums(nums, target, map, false);
    }
    
};
```