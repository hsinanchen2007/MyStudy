#截个图


![dcf13e09812d237b96cf907c99e857f.png](https://pic.leetcode-cn.com/bcd225a0be0a98b4f066f79275e01d43188429af0c5d4a3a8717b62329619b10-dcf13e09812d237b96cf907c99e857f.png)

### 代码

```javascript
/**
 * @param {number[]} arr
 * @param {number} k
 * @return {number[]}
 */
var getLeastNumbers = function(arr, k) {
    return arr.sort((a, b) => a -b).filter((item, i) => i < k)
};
```