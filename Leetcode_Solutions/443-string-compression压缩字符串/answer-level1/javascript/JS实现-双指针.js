[使用JS刷Leetcode](https://github.com/careteenL/data-structure_algorithm/tree/0816-leetcode/src/leetcode)
```js
/**
 * @think 双指针法
 *        1. 指针i表示已经压缩结果的末尾，指针j表示未压缩的头部
 *        2. 当遇到相同的字符串，指针j往后滑动，直到遇到不同的字符
 *             2.1 指针j滑动的距离即为当前字符的长度
 *             2.2 因为这组字符每一项只展示一个字符，故需要将长度转为字符然后挨个赋值
 *        3. 直到未压缩指针j的值指到末尾时，结束遍历
 *             3.1 已经压缩的指针i每次递增到最后即为数组的新长度
 * @param {character[]} chars
 * @return {number}
 */
var compress = function (chars) {
  var len = chars.length
  for (var i = 0, j = 0; j < len;) {
    chars[i] = chars[j]
    var temp = j
    while (j < len && chars[i] === chars[j]) {
      j++
    }
    i++
    var dis = j - temp
    if (dis > 1) {
      var distance = Array.from('' + dis)
      for (var k = 0; k < distance.length; k++) {
        chars[i++] = distance[k]
      }
    }

  }
  return i
}
```
