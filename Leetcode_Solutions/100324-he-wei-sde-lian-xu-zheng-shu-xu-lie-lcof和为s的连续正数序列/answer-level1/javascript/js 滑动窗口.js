就几行代码，简单易懂
### 代码
```javascript
/**
 * @param {number} target
 * @return {number[][]}
 */
var findContinuousSequence = function(target) {
    let max = Math.floor(target / 2) + 1;
    let r = 1, sum = 0, ans = [], temp = [];
    while (r <= max) {
        while (sum < target) {
            sum += r;
            temp.push(r++)
        }
        while (sum >= target) {
            if (sum === target) ans.push([...temp]);
            sum -= temp.shift();
        }
    }
    return ans;
};
```