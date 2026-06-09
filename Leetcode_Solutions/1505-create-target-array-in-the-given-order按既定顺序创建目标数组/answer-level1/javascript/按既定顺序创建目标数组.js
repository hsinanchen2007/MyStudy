### 解题思路
循环index数组，然后判断target[index[i]]是否存在，如果不存在则添加，即target[index[i]]=nums[i];如果不存在则利用数组方法splice在target数组的index[i]处添加值

### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number[]} index
 * @return {number[]}
 */
var createTargetArray = function(nums, index) {
    var target = [];
    index.forEach((item, index)=>{
        if(target[item]!=='undefined') {
            target.splice(item, 0, nums[index]);
        } else {
            target[item] = nums[index];
        }
    });
    return target;
};
```