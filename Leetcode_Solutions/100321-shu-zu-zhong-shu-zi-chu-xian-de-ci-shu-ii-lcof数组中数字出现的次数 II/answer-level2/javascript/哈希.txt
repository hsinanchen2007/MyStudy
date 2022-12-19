### 解题思路
哈希解法

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var singleNumber = function(nums) {
    const map = {};
    for(let i of nums){
        map[i] = (map[i] || 0) +1
    }
    for(let key in map){
        if(map[key] == 1){
            return key
        }
    }

    return 0
};
```