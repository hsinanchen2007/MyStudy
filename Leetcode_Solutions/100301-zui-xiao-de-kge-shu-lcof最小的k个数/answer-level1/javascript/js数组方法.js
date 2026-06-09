### 解题思路
![image.png](https://pic.leetcode-cn.com/c1a3a06dfa08507de7798355ded98819d50587f8333fa39a842fe6a133f4c9f2-image.png)


### 代码

```javascript
/**
 * @param {number[]} arr
 * @param {number} k
 * @return {number[]}
 */
var getLeastNumbers = function(arr, k) {
    return arr.sort((a, b) => a-b).splice(0, k)
};
```