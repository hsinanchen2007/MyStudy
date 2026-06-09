### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var majorityElement = function(nums) {
    const map = new Map()
    for (let i of nums) {
        let count = map.get(i) ? map.get(i) : 0
        map.set( i, ++count)
        if(count >= nums.length / 2){
            return i
        }
    }
};
```