### 解题思路
两次循环 暴力解法 
缺点：性能差 【在所有 JavaScript 提交中击败了5.03%的用户】
### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    var arr=[];
    for(i in nums){
        for(j in nums){
           if ((nums[i]+nums[j])==target &&  i!==j ){
                arr.push(i);
                arr.push(j);
                return arr;
            }
        }
    }
};
```