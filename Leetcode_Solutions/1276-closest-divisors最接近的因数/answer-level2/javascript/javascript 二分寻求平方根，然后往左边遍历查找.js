```
var closestDivisors = function(num) {
  let resultArr = []
  let low = 0
  let high = num + 2
  let middle

  // 二分查找中间点
  while(low < high) {
    middle = low + ((high - low) >> 1)
    const value = middle * middle
    if (value === num + 1 || value === num + 2) {
      resultArr.push(middle, middle)
      // 绝对值肯定是最小
      return resultArr
    } else if (value < num + 2) {
      low = middle + 1
    } else {
      high = middle - 1
    }
  }
    
  // 以low为中点，双指针向两边找
  // 跟上面的high/low命名区分开来
  let left = low
  
  while(left >= 1) {
    if ((num + 1) % left === 0) {
        resultArr.push(left, (num + 1) / left)
        break
    }
    if ((num + 2) % left === 0) {
        resultArr.push(left, (num + 2) / left)
        break
    }
    left--
  }
  return resultArr
};
```
