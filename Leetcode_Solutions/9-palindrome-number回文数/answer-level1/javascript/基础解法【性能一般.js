```
    var isPalindrome = function(x) {
        let str = x.toString()
        return str.split('').reverse().join('') === str
    }
    console.log(isPalindrome(-121))
```
内存和耗时：
![image.png](https://pic.leetcode-cn.com/d8b83986a8eeb89f9b202abc9fa19a54e0fdaa25b1ad4e95bf48154863483a31-image.png)
