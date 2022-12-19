### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var arrayPairSum = function(nums) {
    nums.sort((a,b)=>a-b);
    let res=0, gap=Math.floor(nums.length/2);
    let i=0;
    while(i<nums.length){
        if(i%2==0)
            res+=nums[i];
        i++;
    }
    return res;
};
```