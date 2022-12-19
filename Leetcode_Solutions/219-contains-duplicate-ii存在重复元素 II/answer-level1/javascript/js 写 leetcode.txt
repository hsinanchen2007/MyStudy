呃，，写完发现貌似和大家写的不一样。2333

1. 遍历数组，如果当前值不存在hash表里，把值->key,下标->value,存进hash表
2. 如果当前值在hash表里存在，看下两个值下标的绝对值是否 <= k
3. 如果 <= k，返回true
4. 否则，更新当前值的下标。因为之前的都不成功，如果有下一个相同元素的话绝对值会更大。
5. 循环完成还没有匹配成功，返回false

```js
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {boolean}
 */
var containsNearbyDuplicate = function(nums, k) {
    let hash = new Map()
    
    for(let i = 0; i < nums.length; i++) {
        if(hash.has(nums[i])) {
            if(Math.abs(hash.get(nums[i]) - i) <= k) {
                return true
            } else {
                hash.set(nums[i], i)
            }
        } else {
            hash.set(nums[i], i)
        }
    }
    return false
};
```

https://github.com/zhl1232/javascript-algorithm/tree/master/solve-problems/219.md
