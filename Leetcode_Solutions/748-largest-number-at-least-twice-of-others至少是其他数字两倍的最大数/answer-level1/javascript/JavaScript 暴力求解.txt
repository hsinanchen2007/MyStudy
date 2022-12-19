### 解题思路
- 找到最大值
- 找到最大值索引
- 通过filter过滤器对比每一个数
- 根据长度返回对应值

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var dominantIndex = function(nums) {
    let max = Math.max(...nums)
    let index = nums.indexOf(max)
    nums = nums.filter( item => item * 2 > max)
    return nums.length > 1 ? -1 : index
};
```