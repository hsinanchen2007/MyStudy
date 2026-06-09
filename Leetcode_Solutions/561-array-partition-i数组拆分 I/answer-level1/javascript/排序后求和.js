### 解题思路
观察题目和示例，是将数组排序后，相邻2个数组成对，然后对每个数对的第一个数累计求和。

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var arrayPairSum = function(nums) {
    nums.sort((a,b)=>a-b);
    let len=nums.length;
    let sum=0;
    if(len==0){return 0}
    else {
        for(let i=0;i<len;){
            sum+=nums[i];
            i+=2;
        }
        return sum
    }
};
```