本质上是求因数，注意循环的临界条件为 `Math.sqrt(area)`，因为采用从大到小遍历的方式，因此第一对的因数一定是距离最小的。

```javascript
/**
 * @param {number} area
 * @return {number[]}
 */
var constructRectangle = function(area) {
  var result = [];
  for (var i = Math.sqrt(area) | 0; i > 0; i--) {
    var j = area / i;
    if (j === (j | 0) && j >= i) {
      result = [j, i];
      break;
    }
  }
  return result;
};
```
