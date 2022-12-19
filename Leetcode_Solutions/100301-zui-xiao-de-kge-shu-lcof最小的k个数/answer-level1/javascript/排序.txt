### 解题思路
1.很简单的排序

### 代码

```javascript
/**
 * @param {number[]} arr
 * @param {number} k
 * @return {number[]}
 */
var getLeastNumbers = function(arr, k) {
    const minArrys = arr.sort((a,b)=> a-b);
    return minArrys.slice(0,k)
};
```