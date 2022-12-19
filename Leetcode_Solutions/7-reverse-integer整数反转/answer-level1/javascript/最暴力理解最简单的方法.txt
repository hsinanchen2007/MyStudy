最暴力理解最简单的方法


```
var reverse = function (x) {
    let arr = []
    if (x < 0) {
        let a = Math.abs(parseInt(x))

        let b = a.toString().replace(/\b[0]\b/gi, "")
        for (let i = 0; i < b.length; i++) {
            arr.unshift(b[i])
        }
        if (-(arr.join("")) > -(Math.pow(2, 31)) && -(arr.join("")) < Math.pow(2, 31)) {
            return -(arr.join(""))
        } else {
            return 0
        }


    } else {

        let b = x.toString().replace(/\b[0]\b/gi, "")

        for (let i = 0; i < b.length; i++) {
            arr.unshift(b[i])
        }

        if (arr.join("") > -(Math.pow(2, 31)) && arr.join("") < Math.pow(2, 31)) {
            return arr.join("")
        } else {
            return 0
        }
    }


}

```

![image.png](https://pic.leetcode-cn.com/341dfd762b9e11529becb4d4015c6f846592c08c7d11680d0642f66c219bd334-image.png)
