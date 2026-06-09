### 解题思路
直接使用数组自带的sort方法，进行排序就可以了

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var sortArray = function(nums) {
    return nums.sort((a, b) => {
        return a - b
    })
};
```