### 解题思路
调用splice方法直接插入数据即可

### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number[]} index
 * @return {number[]}
 */
var createTargetArray = function(nums, index) {
    let target = new Array();
    for(let i = 0; i < nums.length; i++){
        target.splice(index[i],0,nums[i])
    }
    return target;
};
```