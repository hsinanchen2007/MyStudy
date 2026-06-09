### 解题思路
求和/3 => 是否能整除
同时从数组两端向中间逐个求和, 和为目标时停止移动指针, 设置flag为true, 两个flag都为true时候返回

### 代码

```javascript
/**
 * @param {number[]} A
 * @return {boolean}
 */
var canThreePartsEqualSum = function (A) {
    let total = A.reduce((pre, next) => {
        return pre + next
    })
    let sum = total / 3
    if (sum === parseInt(sum)) {
        let l = 0, r = A.length - 1, lt = 0, rt = 0, lf = false, rf = false
        while (l < r - 1) {
            if (!lf) {
                lt += A[l]
                if (lt !== sum) {
                    l++
                } else {
                    lf = true
                }
            }
            if (!rf) {
                rt += A[r]
                if (rt !== sum) {
                    r--
                } else {
                    rf = true
                }
            }
            if (lf && rf) {
                return true
            }
        }
        return false
    } else {
        return false
    }
};
```