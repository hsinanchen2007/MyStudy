### 解题思路

倒序排列、弟弟解法

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {boolean}
 */
var isStraight = function(nums) {
    nums.sort((a, b) => b - a) // 倒序排方便大小王剔除
    if (nums.indexOf(0) === -1) { // 没有大小王
        let i = 0
        while (i < 4) {
            if(nums[i] - 1 !== nums[i + 1]) return false // 不是递增就不是顺子
            i++
        }
    } else { // 有大小王
        let i = 0
        let len = 4
        while (i < len) {
            if(nums[i] - 1 !== nums[i + 1]) {
                const index = nums.indexOf(0)
                if (index !== -1) { // 有大小王
                    nums.splice(index, 1) // 去除大小王
                    len--
                    nums[i]--
                    i--
                } else {
                    return false // 没有到大小王直接false
                }
            } // 不是递增就不是顺子
            i++
        }
    }
    return true
};
```