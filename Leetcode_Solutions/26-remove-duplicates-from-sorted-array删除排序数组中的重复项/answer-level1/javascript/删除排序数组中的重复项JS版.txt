### 解题思路
查找循环中元素第一次在数组中出现的位置.
如果和当前index不相等,删除当前元素.
这里i可以放在循环里累加.
这个思路个人感觉还是比较清晰简单的.

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
 var removeDuplicates = function(nums) {
            for(var i=0;i<nums.length;){
                if(i!==nums.indexOf(nums[i]))
                 nums.splice(i,1)
                else i++
            }
            return i
        };
```