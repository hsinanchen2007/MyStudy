官方的题解里每次都会对前后位进行访问，这种方式可以减少这个步骤。

比如[1 0 0 0 1] 这种场景下 从i = 1开始连续命中了3次0 这样就回退一位(i = 2)种花 并且把命中次数重置为1（因为i = 3的位置也是0） 继续匹配。  

对于 [1 0 0]这种边界情况， 虽然只命中了2次0，但是由于到了最后一位，也一样可以种花，做一个边界的判断就ok



```js
/**
 * @param {number[]} flowerbed
 * @param {number} n
 * @return {boolean}
 */
var canPlaceFlowers = function(flowerbed, n) {
  // empty代表连续命中0的次数 命中3次就说明要回退一个种花
  var empty = 1
  var count = 0
  for (var i = 0; i < flowerbed.length; i++) {
    var has = flowerbed[i]
    if (!has) {
      empty++
      // 连续三次空白
      if (empty === 3) {
        // 回退一格种花
        flowerbed[i - 1] = 1
        count++
        // 因为这次没命中 所以又从1开始算
        empty = 1
        if (count >= n) {
          return true
        }
      }
      if (i === flowerbed.length - 1 && empty === 2) {
        count++
      }
    } else {
      empty = 0
    }
  }
  return count >= n
}
```

![image.png](https://pic.leetcode-cn.com/af6f46fd6bc82a856c9116393a1e95d88c3d09bad1e308334e5ca747f7088d01-image.png)
