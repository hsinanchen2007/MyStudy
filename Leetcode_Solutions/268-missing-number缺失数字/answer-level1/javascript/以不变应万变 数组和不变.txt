### 解题思路
![image.png](https://pic.leetcode-cn.com/f8181a8bd42d3ea04a86740df59589e7fdf8c0105666e76da1e106eadf0af8e5-image.png)
从0开始，下标不变，里面的数字不按顺序；但是 有不变的东西，最后的和应该是一定的，所以相加起来，就是固定的 ；但是因为缺少一个 所以 当我们把下标加起来 再加上数组的长度减去数组的和 就是缺少的数字了 


### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var missingNumber = function(nums) {
    let all = 0;
    let all2 = 0;
    for(let i = 0;i<nums.length;i++) {
        all+=nums[i];
        all2+=i;
    };
    return all2+nums.length - all;
};
```