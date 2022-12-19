逆序遍历
```
/**
 * @param {number[]} arr
 * @return {number[]}
 */
var replaceElements = function (arr) {
  let lastMax = -1
  let curMax = -1
  let len = arr.length
  while (len--) {
    curMax = Math.max(arr[len], lastMax)
    arr[len] = lastMax
    lastMax=curMax
  }
  return arr
};
```
