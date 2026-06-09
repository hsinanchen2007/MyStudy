如果用parseInt转换成整数再进行处理，一定会遇到如下字符串不通过的情况：
`"1111011110000011100000110001011011110010111001010111110001"`
输出是81， 但是题目输出是 85
这是因为parseInt转换有问题的。
网上截图：截图出处： http://oceanzhu.com/archives/103
![QQ图片20200405183337.png](https://pic.leetcode-cn.com/466b00c31a218baf0d5ad89a50957c0212c4164ae2b46cb3bad699ce1c37994b-QQ%E5%9B%BE%E7%89%8720200405183337.png)

这里我采用的方法是，用字符串模拟进位和移位操作
首先设定需要的步数 step = 0
1. 当字符串 s 最后一位是 1 的时候，一定是奇数，此时要做 +1 的操作
（1） 最后一位 +1 会造成进位，依次判断前面是否需要进位，直到遇到 0，那么就可以退出循环
（2） 如果遇到形如： "1111"，这种形式，那么在最前面还要再添加一个 1，所以此时需要判断
 step++

2. 如果最后一位是 0， 一定是偶数，此时将字符串右移一位，字符串的长度减一
step++

最后，判断 s 的长度是否等于 1， 然后返回执行的步骤数 step

![QQ截图20200405184232.jpg](https://pic.leetcode-cn.com/82bebb1cd6e4f5fad54fee55d43a61dbf1fc476a614d89aca08c0b4ddedf65b7-QQ%E6%88%AA%E5%9B%BE20200405184232.jpg)


代码如下：
```
/**
 * @param {string} s
 * @return {number}
 */
var numSteps = function(s) {
    let len = s.length
    let res = 0

    while (len !== 1) {
        if (s[len - 1] !== "0") {
            let tmp = 1
            for (let i = len - 1; i >= 0; i--) {
                if ((s[i] === "0" && tmp === 1)) {
                    s = s.substring(0, i) + "1" + s.substring(i + 1)
                    tmp = 0
                    break
                } else if (s[i] === "0" && tmp === 0 || (s[i] === "1" && tmp === 0)) {
                    break
                } else if (s[i] === "1" && tmp === 1) {
                    s = s.substring(0, i) + "0" + s.substring(i + 1)
                    tmp = 1
                }
            }
            if (tmp === 1) {
                s = "1" + s
            }
            res++
        }

        s = s.substring(0, s.length - 1)
        len = s.length
        res++
    }
    return res
};
```
