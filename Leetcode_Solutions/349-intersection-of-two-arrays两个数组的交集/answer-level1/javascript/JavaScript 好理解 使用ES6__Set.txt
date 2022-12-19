### 解题思路
![image.png](https://pic.leetcode-cn.com/b87dac01059146a2f1c219bad1b62a1069d1c9b5e7d63d0b3d87c7bc17dbf221-image.png)
- ES6中Set 对象存储的值总是唯一的
- 通过 filter 取交集
- 然后通过 ES6 解构赋值 重新转化为 数组


### 代码

```javascript
/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number[]}
 */
var intersection = function(nums1, nums2) {
    let a = new Set(nums1)
    let b = new Set(nums2)
    let intersect = new Set([...a].filter(x => b.has(x))); 
    return intersect = [...intersect]
};
```