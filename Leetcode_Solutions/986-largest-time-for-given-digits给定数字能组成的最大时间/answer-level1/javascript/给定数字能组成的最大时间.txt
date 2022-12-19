暴力全排列,参考官方题解

**思路：**

遍历所有可能的时间，找到最大的那个。

**算法：**

用 (i, j, k, l) 表示数组索引 (0, 1, 2, 3)，之后做全排列，对于每个排列，会有 A[i]A[j] : A[k]A[l]。

检查每个排列对应的时间是否合法，例如检查 10\*A[i] + A[j] 是不是小于 24 ；10\*A[k] + A[l] 是不是小于 60。

最后把最大的有效时间输出就可以了。

```js
var largestTimeFromDigits = function(A) {
    let max = -1;
    for(let i = 0; i < 4; i++) {
        for (let j = 0; j < 4; j++) {
            if (j != i) {
                for (k = 0; k < 4; k++) {
                    if ( k!= j && k != i) {
                        // 三个数位置确定了，最后一个数一定是6-i-j-k
                        let l = 6 - i - j - k;
                        let hours = 10 * A[i] + A[j]
                        let mins = 10 * A[k] + A[l]
                        if (hours < 24 && mins < 60) {
                            max = Math.max(max, hours * 60 + mins)
                        }
                    }
                }
            }
        }
    }
    if (max >= 0) {
        let hours = parseInt(max/60) > 9 ? parseInt(max/60) : '0' + parseInt(max/60)
        let mins = parseInt(max%60) > 9 ? parseInt(max%60) : '0' + parseInt(max%60)
        return hours + ':' + mins
    } else {
        return ''
    }
};
```

