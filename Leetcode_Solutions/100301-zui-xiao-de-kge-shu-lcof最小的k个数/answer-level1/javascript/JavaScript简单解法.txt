### 解题思路
数组排序再保留前k个数字

### 代码

```javascript
/**
 * @param {number[]} arr
 * @param {number} k
 * @return {number[]}
 */
var getLeastNumbers = function(arr, k) {
    arr.sort((a,b)=>a-b);
    arr.length = k;
    return arr;
};
```