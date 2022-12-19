### 解题思路

好像也没啥好说的, 就照着题目用代码翻译一遍, 筛选出数组元素长度为偶数, 数字没长度,所以转成字符串了, 返回筛选出的数组长度就行了

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var findNumbers = function(nums) {
    return nums.filter(t => (t+'').length % 2 === 0).length
};
```