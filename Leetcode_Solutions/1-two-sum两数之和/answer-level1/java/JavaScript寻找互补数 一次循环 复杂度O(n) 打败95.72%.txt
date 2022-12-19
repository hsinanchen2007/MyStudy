### 解题思路
diff + nums[i] = target
diff和nums[i]为互补数
所以循环nums时把nums[i]所缺的diff存在一个临时数组中，key为diff，value为i
之后再去临时数组寻找key为nums[i]的值是否存在，存在即为互补数

### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    var temp = [];
    for(var i = 0; i < nums.length; i++) {
        var diff = target - nums[i];
        if(temp[nums[i]] !== undefined) return [temp[nums[i]], i];
        temp[diff] = i;
    }
};
```