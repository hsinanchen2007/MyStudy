### 解题思路
此处撰写解题思路
在使用 数组数据机构时 取模是常用的技巧，也要有逆向思维
### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var rotate = function(nums, k) {
     let cutOutNum=k%nums.length;
     let cutOuArray = nums.splice(-cutOutNum,cutOutNum)
     nums.unshift(...cutOuArray)
};
```