### 解题思路
- 回文排列就是两边单个字符出现的次数需要被2整除。如 'dccaccd'，'c'4次、'd'2次。
- 如果有能出现一次的字符，则取一次，没有则不取

### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */
var longestPalindrome = function(s) {
    let array = s.split('');
    let map = {};
    // 记录每个字符出现的次数
    for(let i = 0; i < array.length; i++) {
        map[array[i]] = map[array[i]] ? map[array[i]] + 1: 1;
    }
    let number = 0; // 长度
    for (let item in map) {
        // 只算出现两次或以上的字符
        if (map[item] >= 2) {
            // 算出字符能够两边排列的次数
            let n = Math.floor(map[item] / 2) * 2
            number += n;
        }
        // 取一个能出现一次的字符，有则取、无则不取
        // 再没取此单个字符前，number 一直为偶数。取了就为奇数
        if (map[item] % 2 == 1 && number % 2 == 0) { 
            number++; 
        }
        
    }
    return number;
};
```