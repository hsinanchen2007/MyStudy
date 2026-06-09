将一个二进制数组转成十进制

**规律：**

`decimal = decimal * 2 + A[i]`

```js
i = 0, decimal = decimal * 2 + A[0] = A[0]

i = 1, decimal = decimal * 2 + A[1] 
               = A[0] * 2 + A[1]

i = 2, decimal = decimal * 2 + A[2] 
               = (A[0] * 2 + A[1]) * 2 + A[2] 
               = A[0] * 2 * 2 + A[1] * 2 + A[2]

i = 3, decimal = decimal * 2 + A[3]
               = (A[0] * 2 * 2 + A[1] * 2 + A[2]) * 2 + A[3]
               = A[0] * 2 * 2 * 2 + A[1] * 2 * 2 + A[2] * 2 + A[3]
...
```

**算法：**

```js
var prefixesDivBy5 = function(A) {
    let res = []
    // 十进制
    let decimal = 0;
    for (let i = 0; i < A.length; i++) {
        // 将二进制都转换成十进制数
        decimal = decimal * 2 + A[i];
        res.push(decimal)
    }
    return res
};
```

var A = [1,1,1,0,1]
AToDecimal = [1, 3, 7, 14, 29]


**思路:**

[1,1,1,0,1]

```shell
第一步：[1] = 0*2+1 = 1;                //被5取模=1
第二步：[1,1] = 1*2+1 = 3;              //被5取模=3
第三步：[1,1,1] = 3*2+1 = 7;            //被5取模=2
第四步：[1,1,1,0] = 7*2+0 = 14;         //被5取模=4
第五步：[1,1,1,0,1] = 14*2+1 = 29;      //被5取模=4
```
如果每步计算 2 的幂，结果会越来越大，考虑采用每次结果的模进行计算

```shell
第一步：[1] = (0*2+1)%5 = 1;            //被5取模=1
第二步：[1,1] = (1*2+1)%5 = 3;          //被5取模=3
第三步：[1,1,1] = (3*2+1)%5 = 2;        //被5取模=2
第四步：[1,1,1,0] = (2*2+0)%5 = 4;      //被5取模=4
第五步：[1,1,1,0,1] = (4*2+1)%5 = 4;    //被5取模=4
```

```js
var prefixesDivBy5 = function(A) {
    let res = []
    // 十进制
    let decimal = 0;
    for (let i = 0; i < A.length; i++) {
        // 将二进制都转换成十进制数
        decimal = decimal * 2 + A[i];
        // 取模
        decimal = decimal % 5;
        if (decimal == 0) {
            res.push(true)
        } else {
            res.push(false)
        }
    }
    return res
};
```


