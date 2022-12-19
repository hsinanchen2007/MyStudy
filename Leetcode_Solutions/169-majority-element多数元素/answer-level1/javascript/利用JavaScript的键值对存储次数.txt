### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var majorityElement = function(nums) {
    const time = nums.length / 2;
    const obj = {};
    const result = [];
    for(let num of nums) {
        if(!obj[num]) {
            obj[num] = 1;
        } else {
            obj[num] = obj[num] + 1;
        }
    }
   for(let key in obj) {
        if(obj[key] > time) {
            result.push(Number(key));
        }
   }
   return result;
    
};
```