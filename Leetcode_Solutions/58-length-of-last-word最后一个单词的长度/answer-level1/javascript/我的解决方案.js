### 解题思路
我是这样操作，看下大家有没有更好的办法优化

### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLastWord = function(s) {
    let arr = s.split(" ");
      let res = []
      let currentIndex = arr.length - 1
      let lastStr = arr[currentIndex]
      res.push(lastStr)
      while (res.length) {
        let v = res.shift();
        if (v.length === 0) {
          currentIndex--
          if (currentIndex >= 0) {
            res.push(arr[currentIndex])
          } else {
            return 0
          }
        } else {
          return v.length
        }
      }
};
```