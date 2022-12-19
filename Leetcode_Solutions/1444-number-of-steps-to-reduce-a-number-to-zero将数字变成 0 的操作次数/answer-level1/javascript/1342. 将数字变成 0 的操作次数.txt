### 解题思路

- 如果 $num = 0$，那么 ``return 0``
- 如果 $num$ 为偶数，那么 $num / 2$ 并递归
- 如果 $num$ 为奇数，那么 $num - 1$ 并递归

### 代码

```javascript
/**
 * @param {number} num
 * @return {number}
 */
var numberOfSteps  = function(num) {
    if (num === 0) {
        return 0
    }
    if (num % 2 === 0) {
        return numberOfSteps(num / 2) + 1
    }
    return numberOfSteps(num - 1) + 1
};
```