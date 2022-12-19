### 解题思路
我是蠢

### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var searchInsert = function(nums, target) {
    for(var i=0;i<nums.length;i++){
        if(nums[i] === target ){
            return i;
        }else{
            // 向数组末尾添加那个不存在的数
            nums.push(target);
            // 排序数组
            nums = nums.sort(function(a,b){return a - b;})
            // 在遍历一次检查target的索引位置
            for(var j=0;j<nums.length;j++){
                if(nums[j] === target ){
                    return j;
            }
            }
        }
        
    }
};
```