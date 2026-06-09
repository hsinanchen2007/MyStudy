### 解题思路
for循环对比guess和answer数组的第一项，相等就是猜对

### 代码

```javascript
/**
 * @param {number[]} guess
 * @param {number[]} answer
 * @return {number}
 */
var game = function(guess, answer) {
    let count = 0
    for(let i=0; i<answer.length; i++) {
        if (guess[i] === answer[i]) count++
    }
    return count
};
```