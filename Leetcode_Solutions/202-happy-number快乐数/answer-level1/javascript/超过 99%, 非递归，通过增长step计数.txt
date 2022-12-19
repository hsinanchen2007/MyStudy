## 假设求解过程是无限循环的，那必然存在循环的长度，假设长度为step, 计数count 如果未出现循环就增大 step， 重制count = 0

```javascript
/**
 * @param {number} n
 * @return {boolean}
 */
var isHappy = function(n) {
    if (n === 0) {
        return false
    }
    let last = ''
    let step = 1
    let count = 0
    let tmp = n + ''
    while(true) {
        if (/^10*$/.test(tmp)) {
            return true
        }
        if (last === tmp) {
            return false
        }
        if (count === step) {
            last = tmp
            step = step + 1
            count = 0
        }
        count ++
        tmp = tmp.split('').reduce((sum, it) => sum + it * it, 0) + ''
    }
};
```