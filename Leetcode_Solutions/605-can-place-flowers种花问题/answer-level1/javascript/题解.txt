### 解题思路
1、扫描数组，如果0的左边和右边都是0，把这个0变成1，计数
2、注意第一个和最后一个只需一侧为0即可的特殊情况
3、数组头尾添加0，用来覆盖特殊情况

### 代码

```javascript
/**
 * @param {number[]} flowerbed
 * @param {number} n
 * @return {boolean}
 */
var canPlaceFlowers = function(flowerbed, n) {
  // 头尾各看做 0
  flowerbed.unshift(0)
  flowerbed.push(0)
  // 计算能够插入的最大值
  let max = 0
  // 第2个开始, 倒数第2个结束
  for (let i = 1, len = flowerbed.length - 2; i <= len; i++) {
    if (
      flowerbed[i] === 0 && 
      flowerbed[i - 1] === 0 && 
      flowerbed[i + 1] === 0
    ) {
      flowerbed[i] = 1
      max++
    }
  }
  // 成功条件：
  return max >= n
};
```