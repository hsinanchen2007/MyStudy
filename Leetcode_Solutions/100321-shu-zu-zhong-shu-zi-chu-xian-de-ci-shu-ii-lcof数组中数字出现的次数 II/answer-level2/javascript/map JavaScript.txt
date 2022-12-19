### 解题思路
遍历一遍。。。。

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var singleNumber = function(nums) {
    let map = new Map()
    nums.forEach(ele => {
        if(map.has(ele)) map.set(ele, false) 
        else map.set(ele, true)
    })
    let res
    map.forEach((value, key) => {
        if(value) res = key
    })
    return res
};
```