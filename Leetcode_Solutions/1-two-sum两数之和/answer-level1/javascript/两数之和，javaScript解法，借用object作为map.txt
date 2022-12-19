### 解题思路
假设每种输入只会对应一个答案降低了难度，如果有三个相同值，两两相加得到target，此方法只能找到第一个和第三个值的索引

### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    let obj = {}; 
    for(let i=0;i<nums.length;i++) {
        obj[nums[i]] = i;
        //此处其实有取巧，如果不同索引位置出现相同值，后来者会覆盖前者的值
        //所以在for循环中，如果两值相同，obj里不会出现前者的索引
    }
    for(let i=0;i<nums.length;i++) {
        const aim = target - nums[i];
        if(obj.hasOwnProperty(aim) && obj[aim] !== i) { 
            return [i,obj[aim]]; 
        }
    }
}
```