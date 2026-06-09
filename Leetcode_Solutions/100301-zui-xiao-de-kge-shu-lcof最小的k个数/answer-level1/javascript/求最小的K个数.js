### 解题思路
最简单的思路就是先排序然后切片，代码简单，但是执行的效率并不是很高。
排序的时间复杂的是nlogn。所以整个算法的时间复杂度是nlogn

### 代码

```javascript
/**
 * @param {number[]} arr
 * @param {number} k
 * @return {number[]}
 */
var getLeastNumbers = function(arr, k) {
    arr.sort((x,y)=>x-y)
    return arr.slice(0,k)
};
```