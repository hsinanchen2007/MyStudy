### 解题思路

- 利用哈希表，将数组中的数字作为 ``key``，用 ``boolean`` 值标记是否出现过
- 从 ``1`` 到 ``nums.length`` 遍历一次，每次从哈希表中取 ``key`` 值，判断该值是否被标记过
- 没有被标记过的值 ``push`` 到数组里面

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var findDisappearedNumbers = function(nums) {
    const map = new Map(), res = []
    for (const num of nums) {
        const val = map.get(num)
        map.set(num, true)
    }
    for (let i = 1; i <= nums.length; i++) {
        if (!map.get(i)) {
            res.push(i)
        }
    }
    return res
};
```