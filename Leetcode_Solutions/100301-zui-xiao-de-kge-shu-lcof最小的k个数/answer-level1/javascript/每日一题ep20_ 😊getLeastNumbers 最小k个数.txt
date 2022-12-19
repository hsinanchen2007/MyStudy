## 一、sort排序

sort排序slice截取

sort排序是基于快排，故时间复杂度O(nlogn) 空间复杂度O(logn)

```js
var getLeastNumbers = function(arr, k) {
    return arr.sort((a, b) => a - b).slice(0, k)
};
```
## 二、基于快排的
## 三、实现最小堆
