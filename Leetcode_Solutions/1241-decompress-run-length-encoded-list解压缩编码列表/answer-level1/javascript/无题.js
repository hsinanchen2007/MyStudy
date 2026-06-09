### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var decompressRLElist = function(nums) {
    const res = []
    while(nums.length){
        const pair=nums.splice(0, 2);
        let [n, m] = pair;
        while(n-->0)res.push(m);
    }
    return res;
};
```