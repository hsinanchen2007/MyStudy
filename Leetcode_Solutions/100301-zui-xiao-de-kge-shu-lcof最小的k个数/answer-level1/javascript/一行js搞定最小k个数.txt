### 解题思路
对数组按从小到大进行排序，然后返回前k个数据即可

### 代码

```javascript
/**
 * @param {number[]} arr
 * @param {number} k
 * @return {number[]}
 */
var getLeastNumbers = function(arr, k) {
    return arr.sort((a, b) => a-b).slice(0, k)
};
```