
![image.png](https://pic.leetcode-cn.com/56f96a0887458e3cf7dffcad268000d6e4db4add33a632e1bbccf5fd459a54bd-image.png)
利用left和right两个指针, right指针前移的时候, 去检测max值, left指针前移的时候，直接进去下一个循环
```javascript []

var lengthOfLongestSubstring = function(str) {
    if (str.length <= 1) {return str.length}
      let left = 0
      let right = 1
      let max = 0
      let temp
      while(right<str.length){
        temp = str.slice(left, right)
        if (temp.indexOf(str.charAt(right)) > -1) {
          left++
          continue
        } else {
          right++
        }
        if (right - left > max) { max = right - left }
      }
      return max
};

```

