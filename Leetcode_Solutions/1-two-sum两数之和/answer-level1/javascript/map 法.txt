### 解题思路

1. 时间复杂度为 O(n)
2. 空间复杂度为 O(n)
3. 利用 map

### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    const map = {};

    nums.forEach((num, index) => {
        map[num] = index;
    });

    let pos1 = -1;
    let pos2 = -1;

    for (let i = 0, len = nums.length; i < len; i++) {
        pos1 = i;
        const nextNum = target - nums[i];
        const nextPos = map[nextNum];
        if (nextPos !== i && nextPos !== undefined) {
            pos2 = map[nextNum];
            break;
        }
    }

    return [ pos1, pos2 ];
};
```