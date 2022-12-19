### 解题思路
先判断限制条件

要求解析条件需要分解出前k个最小的值就排序裁剪即可

### 代码

```javascript
/**
 * @param {number[]} arr
 * @param {number} k
 * @return {number[]}
 */
var getLeastNumbers = function(arr, k) {
    if (arr.length < k || arr.length > 10000) return []
    if (arr.filter(v => v > 10000 || v < 0).length) return []
    return arr.sort((a, b) => a - b).slice(0, k)
};
```