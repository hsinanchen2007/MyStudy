### 解题思路
看代码

### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var search = function(nums, target) {
    const map = {}
    for(let i of nums){
        map[i] = (map[i] || 0) + 1
    }

    for(let key in map){
        if(key == target){
            return map[key]
        }
    }

    return 0;

};
```