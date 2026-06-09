**需要注意的点**

  这道题和实际项目有点区别，拿凑单逻辑来说相同价格不同商品ID是可以组合的。也就是相当于输入数组中索引不同但是数字的相同的是可以重复的。例如：[0,0,0,0] 按业务逻辑通常是 [0,0,0] [0,0,0,] 因为是不同的商品
  但这道题既不允许相同位置的几个数字组合，也不允许不同位置上数字相同的几个数组合 例如[0,0,0,0] 输出 [0,0,0];

```
var threeSum = function (arr) {
      if (arr.length < 3) return [];
      var map = {};
      arr = arr.sort((a, b) => a - b);
      var res = []
      var i = 0;
      var left = 0;
      var sum = 0;
      var right = 0;
      var mark = false;
      for (; i < arr.length - 2; i++) {
        if (mark) { if (arr[i] !== arr[i + 1]) { mark = false }; continue; } //这两句话保证排除不同位置的已存在数字组合，也保证不会丢失项
        left = i + 1;
        right = arr.length - 1;
        while (left < right) {
          sum = arr[left] + arr[right] + arr[i];
          if (sum > 0) {
            right--;
          } else if (sum < 0) {
            left++;
          } else {
                          res.push([arr[i], arr[left], arr[right]]);

            while (left < right && arr[left] == arr[left + 1]) {
              left++;
            }
            while (left < right && arr[right] == arr[right - 1]) {
              right--;
            }

            left++;
            right--;
          }
        }
        if (arr[i] === arr[i + 1]) { mark = true; } //这两句话保证排除不同位置的已存在数字组合，也保证不会丢失项
      }
      return res;
    };
```

  
