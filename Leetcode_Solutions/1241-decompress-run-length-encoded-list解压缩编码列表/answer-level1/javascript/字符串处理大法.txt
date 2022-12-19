### 解题思路

执行用时 :116 ms, 在所有 JavaScript 提交中击败了13.00%的用户
内存消耗 :37.7 MB, 在所有 JavaScript 提交中击败了100.00%的用户

字符串处理大法，效率真低😂😂😂

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var decompressRLElist = function(nums) {
  return nums.join(',').match(/\d+,\d+/g).map(item => {
    const [len,num] = item.split(',');
    return (num + ',').repeat(len - 0).replace(/,$/,'');
  }).reduce((sum,curr) => sum + ',' + curr).split(',');
};
```