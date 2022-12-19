### 解题思路
- 用个对象来记录出现的次数
- 

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var majorityElement = function(nums) {
    const map = {}
    const len = nums.length >>> 1;
    for(let i of nums){
        map[i] = (map[i] || 0) + 1;

    }
    for(let key in map){
        if(map[key] > len){
            return key
        }
    }

    return 0
};
```