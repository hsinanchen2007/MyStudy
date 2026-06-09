### 解题思路
/**
 * 1.判断边界条件
 * 2.将数组按照升序排序
 * 3.遍历数组，统计result[]和max值
 *   result记录每一个连续序列，max则统计resul的最大长度，
 * 4.如果入到相同数字，则不插入数组
 */

### 代码

```javascript
/**
 * 1.判断边界条件
 * 2.将数组按照升序排序
 * 3.遍历数组，统计result[]和max值
 *   result记录每一个连续序列，max则统计resul的最大长度，
 * 4.如果入到相同数字，则不插入数组
 */

/**
 * @param {number[]} nums
 * @return {number}
 */
var longestConsecutive = function(nums) {
    if (!nums || (nums && nums.length === 0)) {
        return 0;
    }
    nums = nums.sort(function(a, b) {
        return a-b;
    });

    let result = [nums[0]];
    let max = 1;
    for (let i = 1; i < nums.length; i++) {
        if((result[result.length-1] === nums[i]) 
            || (result[result.length-1] + 1 === nums[i])) {
            if (result.indexOf(nums[i]) < 0) {
                result.push(nums[i])
            }
            if (max < result.length) {
                max = result.length;
            }
        } else {
            if (max < result.length) {
                max = result.length;
            }
            result = [nums[i]];
        }
    }
    return max;
};
```