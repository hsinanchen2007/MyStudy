### 解题思路
![image.png](https://pic.leetcode-cn.com/f92575174fcfe0616e5f65ed58caa04212e8fd7253db4ad215f9bb89da31f0b7-image.png)
- 通过 reduce 进行迭代

### 代码

```javascript
/**
 * @param {number} n - a positive integer
 * @return {number}
 */
var hammingWeight = function(n) {
    let arr = n.toString(2).split('') 
    return arr.reduce((pre,next) => {return Number(pre) + Number(next)})
};
```