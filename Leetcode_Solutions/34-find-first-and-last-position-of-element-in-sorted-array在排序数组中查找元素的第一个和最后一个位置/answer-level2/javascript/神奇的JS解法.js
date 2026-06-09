```js
// 解法一：使用二分查找
var searchRange = function(nums, target) {
  const findIndex = (arr, target, position = 'first') => {
    let minIndex = 0;
    let maxIndex = arr.length - 1;
    let midIndex, midValue;

    while (minIndex <= maxIndex) {
      midIndex = ~~((maxIndex + minIndex) / 2);
      midValue = arr[midIndex];

      if (midValue === target) {
        if (position === 'first' && arr[midIndex - 1] === target) {
          maxIndex = midIndex - 1;
        } else if (position === 'last' && arr[midIndex + 1] === target) {
          minIndex = midIndex + 1;
        } else {
          return midIndex;
        }
      } else if (midValue > target) {
        maxIndex = midIndex - 1;
      } else if (midValue < target) {
        minIndex = midIndex + 1;
      }
    }

    return -1;
  };

  return [findIndex(nums, target, 'first'), findIndex(nums, target, 'last')];
};
```


```js
// 方法二：呃呃呃，使用js数组的原生方法，比方法一慢4毫秒左右
var searchRange = function(nums, target) {
  return [
    nums.findIndex(el => el===target),
    nums.lastIndexOf(target)
  ];
};
```
