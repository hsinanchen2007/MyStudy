### 解题思路

1. 用a+b与b+a来比较大小排序
2. 将数组转为字符串
3. 就完成了

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {string}
 */
var minNumber = function(nums) {
    return nums.sort((a,b) => ('' + a + b) - ('' + b + a)).join('');
};
```