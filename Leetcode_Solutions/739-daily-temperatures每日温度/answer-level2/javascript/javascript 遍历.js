### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} T
 * @return {number[]}
 */
 var dailyTemperatures = function(T) {
    const len = T.length
    const res = []
    if (len) {
        for (let i = 0; i < len; i++) {
            let day = 0
            for (let j = i + 1; j < len; j++) {
                if (T[j] > T[i]) {
                    day = j - i
                    break
                }
            }
            res.push(day)
        }
    }
    return res
};
```