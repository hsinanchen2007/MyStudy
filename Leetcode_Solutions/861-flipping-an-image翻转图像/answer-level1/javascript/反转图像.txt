```javascript []
var flipAndInvertImage = function (A) {
    let brr = []
    A.map(res => {
        brr.push(res.reverse().map(d => {
            return d = d === 0 ? 1 : 0
        }))
    })
    return brr
};

/**
 * 解题思路：
 * 
 *  1. 拿到数组后，先按照题意反转数组内的每一个数组
 *  2. 再将反转后的数组中的每一项进行修改所对应的数字0或1
 */
```

