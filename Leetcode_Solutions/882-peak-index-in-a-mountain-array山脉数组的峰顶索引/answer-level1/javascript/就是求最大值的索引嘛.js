### 解题思路
说了一大堆, 没怎么听懂, 这特么不就是求最大值的索引嘛

### 代码

```javascript
/**
 * @param {number[]} A
 * @return {number}
 */
var peakIndexInMountainArray = function(A) {
    return A.indexOf(Math.max(...A))
};
```