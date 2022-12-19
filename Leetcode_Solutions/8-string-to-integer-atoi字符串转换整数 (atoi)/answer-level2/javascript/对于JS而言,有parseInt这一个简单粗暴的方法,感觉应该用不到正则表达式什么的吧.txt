对于JS而言,这个题就是这么的简单粗暴,就是不知道对于其他编程语言而言高效不高效
![Screenshot from 2020-02-05 20-40-00.png](https://pic.leetcode-cn.com/c8db13772470b327dc69af143a86c69b3837f30d46573d6c902a2eae86e4bf09-Screenshot%20from%202020-02-05%2020-40-00.png)

```javascript
var myAtoi = function (str) {
    let res = parseInt(str)
    if (isNaN(res)) {
        return 0
    } else {
        if (res > 2147483647) {
            return 2147483647
        } else if (res < -2147483648) {
            return -2147483648
        } else {
            return res
        }
    }
}
```


