### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
// 大概是类似于json存储信息的做法 先固定一个参数 然后再第二个符合目标的值
// 先把循环数组存放到对象中 就是下面的代码
// obj[nums[i]] = i; 
// 接下来用  目标值 - 固定的值 如果不等于undefined 就返回结果 
// 相反将继续固定下一个目标值
var twoSum = function (nums, target) {
    let obj = {};
    for (var i = 0; i < nums.length; i++) {
        if (obj[target - nums[i]] !== undefined) {
            return [obj[target - nums[i]], i];
        }
        obj[nums[i]] = i;
    }
};
```