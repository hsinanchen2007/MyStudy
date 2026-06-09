### 执行结果
![image.png](https://pic.leetcode-cn.com/30f931e2c0926c859ba75e58a823c3066c565ca322dfe4d407d5e65ef7ad0e66-image.png)

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var subsets = function (nums) {
  return nums.reduce((res, num) => res.concat(res.map(i => i.concat(num))), [[]]);
};
```