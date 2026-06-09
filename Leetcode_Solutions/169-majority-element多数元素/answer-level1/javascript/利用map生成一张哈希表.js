### 解题思路
此处撰写解题思路
将给定数组nums中的元素映射到一张哈希表中，拿到给定数组的长度n。遍历哈希表中每个key的value值，也就是看每个元素都出现了几次，如果大于n/2，就把这个元素返回。
### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var majorityElement = function(nums) {
    let map = new Map()
    for (let i = 0; i < nums.length; i++) {
        if (map.has(nums[i])) {
            map.set(nums[i], map.get(nums[i]) + 1)
        } else {
          map.set(nums[i], 1)
        }
    }
    const len = nums.length
    for (let item of map.entries()) {
        if (item[1] > len / 2) {
            return item[0]
        }
    }
};
```