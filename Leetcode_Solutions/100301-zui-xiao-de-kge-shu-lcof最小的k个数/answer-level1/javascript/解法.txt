### 解题思路
此处撰写解题思路
排序，然后用数组的slice函数返回以0到k位置的元素组成的数组
### 代码

```javascript
/**
 * @param {number[]} arr
 * @param {number} k
 * @return {number[]}
 */
var getLeastNumbers = function(arr, k) {
    arr.sort(function(a, b){return a - b})
    return arr.slice(0,k)
};
```