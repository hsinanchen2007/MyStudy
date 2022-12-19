![k.jpg](https://pic.leetcode-cn.com/a145cf8d44e526d80b70fd033968d8f05980de46680e658988a7e0705086f78d-k.jpg)
### 解题思路
二分查找

### 代码

```javascript
/** 
 * Forward declaration of guess API.
 * @param {number} num   your guess
 * @return 	            -1 if num is lower than the guess number
 *			             1 if num is higher than the guess number
 *                       otherwise return 0
 * var guess = function(num) {}
 */

/**
 * @param {number} n
 * @return {number}
 */
var guessNumber = function(n) {
    let low = 1;
    let high = n;
    while (low <= high) {
        let mid = low + Math.floor((high - low) / 2);
        let res = guess(mid);
        if (res == 0) {
            return mid;
        } else if (res < 0) {
            high = mid - 1
        } else {
            low = mid + 1
        }
    }
    return -1;
};
```