### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var majorityElement = function(nums) {
    const map = nums.reduce((o, n)=>{o[n]=o[n]?o[n]+1:1; return o}, {});
    const keys = Object.keys(map);
    for(let key of keys){
        const times = map[key];
        if(times/nums.length>0.5)return key;
    }
    return -1;
};
```