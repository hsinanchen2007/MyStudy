### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var singleNumber = function (nums) {
    let hash = nums.reduce((cur, next) => {
        if (next in cur) cur[next]++;
        else cur[next] = 1;
        return cur;
    }, {})
    
    for (let val in hash) {
        if (hash[val] === 1) return val;
    }
};
```