思路：将一个整数数组nums分割成k个连续数字，首先如果k为1，则肯定返回true；如果数组的长度不是k的倍数，则肯定无法分隔成长度为k的数个数组，返回false

因为分割的数组内是连续数字，首先将nums按从大到小排序，每次取nums的第一个数字a，判断nums里是否包含a+1, a+2, a+3 …… a+k-1,若nums里包含，则用splice方法将该数字移除；若nums里不包含，则直接返回false。直到nums长度为0，结束循环

```
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {boolean}
 */
var isPossibleDivide = function(nums, k) {
    if (k === 1) return true
    let len = nums.length
    if (len%k !== 0) return false
    nums = nums.sort((a, b) => {
        return a - b
    })
    while(nums.length > 0) {
        let num = nums.shift()
        for (let i = 1; i < k; i++) {
            const idx = nums.indexOf(++num)
            if (idx === -1) return false
            nums.splice(idx, 1)
        }
    }
    return true
};
```
