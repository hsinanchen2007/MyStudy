### 解题思路
二分查找思想
由于数组是一个递增的有序数组旋转而成，所以
- 如果最右侧比中间大，说明右侧是持续递增的，最小值不在右侧
- 如果最右侧比中间小，说明递增数组被打断，最小一定在右侧
- 遇到两者相等的情况将最右侧的数排除即可

### 代码

```javascript
/**
 * @param {number[]} numbers
 * @return {number}
 */
var minArray = function(numbers) {
  let left = 0, right = numbers.length - 1, mid
  while (left < right) {
    mid = Math.floor((left + right) / 2)
    if (numbers[right] > numbers[mid]) { // 右侧为递增 排除之
      right = mid
    } else if (numbers[right] < numbers[mid]) { // 左侧一定有最小值
      left = mid + 1
    } else right-- // 去重
  }
  return numbers[left]
};
```

