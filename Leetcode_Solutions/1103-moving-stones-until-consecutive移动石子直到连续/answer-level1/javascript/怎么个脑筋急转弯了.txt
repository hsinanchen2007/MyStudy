### 解题思路
![image.png](https://pic.leetcode-cn.com/d434f11ef7eb38e424d939e5880059ed68cbe789107f34c741d091e839ea01e4-image.png)

就是两个当中隔一位的时候，可以直接跳过去。

### 代码

```javascript
/**
 * @param {number} a
 * @param {number} b
 * @param {number} c
 * @return {number[]}
 */
var numMovesStones = function (a, b, c) {
    let arr = [a, b, c].sort((a, b) => a - b);
    let ret = [0, 0];
    ret[0] = (arr[2] - arr[1] === 2 || arr[1] - arr[0] === 2) ? 1 : (arr[1] === arr[0] + 1 ? 0 : 1) + (arr[2] === arr[1] + 1 ? 0 : 1);
    ret[1] = (arr[1] - arr[0] - 1) + (arr[2] - arr[1] - 1);
    return ret;
};
```