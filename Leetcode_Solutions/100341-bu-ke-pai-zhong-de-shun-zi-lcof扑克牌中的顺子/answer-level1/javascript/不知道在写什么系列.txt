### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {boolean}
 */
var isStraight = function(nums) {

    nums.sort((a, b) => a - b)

    let zeroes = 0 // 5张牌中大小王的数量!
    for (let i = 0; i < 4; i++) {
        if (!nums[i]) {
            zeroes++
            continue
        }

        if (nums[i] === nums[i + 1]) // 有重复的牌!
            return 0
    }

    if (!zeroes) // 等差数列求公差公式 (公差 =（末项-首项）/（项数-1）)
        return (nums[4] - nums[0]) / 4 === 1 

    for (let i = zeroes; i < 4; i++) {

        if (nums[i + 1] - nums[i] !== 1) {  // 用大小王填...
            zeroes -= nums[i + 1] - nums[i] - 1
            
            if (zeroes < 0) return 0
        }
    }

    return 1
};
```