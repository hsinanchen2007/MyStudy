### 解题思路

暴力循环

### 代码

```javascript
/**
 * @param {number} target
 * @return {number[][]}
 */
var findContinuousSequence = function(target) {
    const result = []
    let sum = 0, current = 0, temp = []
    for (let i = 1; i < target; i++) {
        sum = 0
        current = i
        temp = []
        while (sum < target) {
            sum += current
            if (sum === target) {
                let j = i
                while (j < current + 1) {
                    temp.push(j)
                    j++
                }
                result.push(temp)
            }
            current++
        }
    }
    return result
};
```