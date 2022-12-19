思路非常简单清晰, 但成绩还算不错.
1. 利用 Map 存储出现的数字和对应次数.
2. 遍历 Map 找到出现次数最多的数字. 这里没有考虑 n / 2

![WX20190615-182813@2x.png](https://pic.leetcode-cn.com/e6077681961ac948a499d1ace2c5339dbaf1252209091eaf39cc6ecc31c0affe-WX20190615-182813@2x.png)

```
/**
 * @param {number[]} nums
 * @return {number}
 */
var majorityElement = function(nums) {
    let cache = new Map();
    nums.forEach((num) => {
        if(cache.has(num)) {
            cache.set(num, cache.get(num) + 1);
        } else {
            cache.set(num, 1);
        }
    })
    let target = [null, 0];
    cache.forEach((val, key) => {
        if(val > target[1]) {
            target = [key, val]
        }
    })
    return target[0];
};
```