### 解题思路
首先对数组排序
其次从排序后的数组中取k个数
最后将取出的数组返回即可
### 代码

```javascript
/**
 * @param {number[]} arr
 * @param {number} k
 * @return {number[]}
 */
// 首先对数组排序
// 其次从排序后的数组中取k个数
var getLeastNumbers = function(arr, k) {
    arr.sort((a, b) => {
        return a - b
    })
    return arr.splice(0, k)
};
```