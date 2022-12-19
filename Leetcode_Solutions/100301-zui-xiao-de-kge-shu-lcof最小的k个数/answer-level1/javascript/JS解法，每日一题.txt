### 解题思路
数组排序，截取前k个

### 代码

```javascript
/**
 * @param {number[]} arr
 * @param {number} k
 * @return {number[]}
 */
var getLeastNumbers = function(arr, k) {
    return arr.sort((a,b)=>a-b).slice(0,k)
};
```