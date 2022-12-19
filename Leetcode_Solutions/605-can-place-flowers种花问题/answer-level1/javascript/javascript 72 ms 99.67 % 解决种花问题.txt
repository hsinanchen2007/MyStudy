思路：
1. 给数组两端各加0为边界
2. 使用reduce遍历数组，并判断当前是否为0，两侧是否为0，如果满足，累加器加1，并修改当前值为1
3. 注意遍历的时候要避开第一位和最后一位，它们只是辅助元素
```javascript
var canPlaceFlowers = function (flowerbed, n) {
  flowerbed = [0, ...flowerbed, 0]
  return flowerbed.reduce((pre, curValue, index) => {
    if (index === 0 || index === flowerbed.length - 1) return pre
    if (curValue === 0 && flowerbed[index - 1] === 0 && flowerbed[index + 1] === 0) {
      pre++
      flowerbed[index] = 1
    }
    return pre
  }, 0) >= n
};
```
![image.png](https://pic.leetcode-cn.com/7fc9ce5bc8fda715588b350668086f461e2c386c0897011ab196f0774fd1b9c9-image.png)
