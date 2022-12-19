![1.png](https://pic.leetcode-cn.com/97f10de3cd7507e496c30b082086874fceec94b2834456a0f233900205bb66d2-1.png)

数值反转
```
var reverse = function (x) {
    let fu = ''
    if (x < 0) {
        fu = '-'
        x = Math.abs(x)
    }
    var ar = (x + "").split("")
    let leng = ar.length
    var reve = []
    for (let i = leng - 1; i >= 0; i--) {
        reve.push(ar[i])
    }
    let res = Number(fu + reve.join(''));
    let max = Math.pow(2, 31);
    if (res < (-1 * max) || res > (max - 1)) {
        return 0;
    }
    return res
};
```
