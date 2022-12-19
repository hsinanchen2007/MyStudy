### 解题思路
1.哈希记录

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var singleNumbers = function(nums) {
    const map = {}
    const result = []
    for(let i of nums){
        map[i] = (map[i] || 0) +1
    }

    for(let key in map){
        if(map[key] == 1){
            result.push(key)
        }
    }

    return result

};
```