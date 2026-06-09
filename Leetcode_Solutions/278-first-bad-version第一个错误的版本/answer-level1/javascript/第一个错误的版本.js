### 解题思路

考点：二分查找

注意：开始值和结束值的选取；二分结果是小数的处理

### 代码

```javascript
var solution = function(isBadVersion) {
    return function(n) {
      if (n === 1) return n;
      let start = 0;
      let end = n;
      let middle = Math.ceil((start + end) / 2);
      while (start < end - 1) {
        if (isBadVersion(middle)) {
          end = middle;
        } else {
          start = middle;
        }
        middle = Math.ceil((start + end) / 2);
      }
      return middle;
    };
};
```