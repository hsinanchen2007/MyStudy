### 解题思路
O(n) 解法，哈希表存储。遍历数组，如果元素初次遍历就放入表中，如果遍历到表中已经有的元素就返回该元素。

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var findRepeatNumber = function (nums) {
    if (!nums) return
    let map = new Map();
    for (let i = 0; i < nums.length; i++) {
        if (map.has(nums[i])) {
            return nums[i]
        } else {
            map.set(nums[i], i)
        }
    }
};
```
![搜索框传播样式-标准色版.png](https://pic.leetcode-cn.com/5b693dce2ea930fe7d095fbb126cc9e8b0d109de3e59c4f09c898d62a09d7a9b-%E6%90%9C%E7%B4%A2%E6%A1%86%E4%BC%A0%E6%92%AD%E6%A0%B7%E5%BC%8F-%E6%A0%87%E5%87%86%E8%89%B2%E7%89%88.png)
