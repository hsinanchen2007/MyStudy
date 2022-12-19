### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var findRepeatNumber = function(nums) {
    nums.sort((a,b)=>a-b);
    let tmp;
    for(let n of nums){
        if(tmp!=undefined && n==tmp)return n;
        tmp=n;
    }
};
```