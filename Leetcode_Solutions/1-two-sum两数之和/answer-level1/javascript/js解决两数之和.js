### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    for (let i = 0; i < nums.length; i++) {
        //j从i的后一位开始循环，提高速度
        for (let j = i + 1; j < nums.length; j++) {
            //如果两数之和等于target
            if(nums[i] + nums[j] == target)
                //返回i和j
                return [i,j];
        }
    }
}

```
此代码耗时132ms，内存34.8mb。