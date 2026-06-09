### 解题思路
第一次在 LeetCode 做题，直接就用稍微记得一点的 JavaScript 了。
原理很简单，就是暴力跑。
再去试试 C 的。

### 代码

```javascript
var twoSum = function(nums, target) {
    for(let i = 0,len = nums.length;i<len;i++){
        for(let j = i+1;j<len;j++){
            if(nums[i]+nums[j] == target) 
            return [i,j];
         }
    }
};
```