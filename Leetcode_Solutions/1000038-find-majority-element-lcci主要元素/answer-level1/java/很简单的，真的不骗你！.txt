# 思路：
1. 循环的同时，计算每个数字出现的次数
2. 每次循环，保留最大值，同时进行判断是否出现的次数大于一半
3. 如果找到直接返回！

![image.png](https://pic.leetcode-cn.com/18d181ce0127092922b2419144ff8ff3aad130924a97045aa27a9d4a298a02b0-image.png)

```
/**
 * @param {number[]} nums
 * @return {number}
 */
var majorityElement = function (nums) {
    let len = nums.length / 2, m = new Map(), res = -1, max = Number.MIN_SAFE_INTEGER
    for (let num of nums) {
        m.set(num, m.has(num) ? m.get(num) + 1 : 1)
        max = Math.max(max, m.get(num))
        if (max > len) {
            return num
        }
    }
    return res
};
```
