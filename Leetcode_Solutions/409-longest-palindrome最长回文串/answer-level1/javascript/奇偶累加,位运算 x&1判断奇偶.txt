### 解题思路

还是空间换时间吧

### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */
var longestPalindrome = function(s) {
    if(s.length === 0) return 0
    var map = {}
    for(let i = 0;i<s.length;i++){
        map[s[i]] = map[s[i]] || 0
        map[s[i]]++
    }

    // 累加所有偶数
    let allEven = 0
    // 寻找最长奇数
    let maxOdd = 0

    for(let i of Object.keys(map)){
        // 位运算判断奇偶
        if(!(map[i] & 1)){
            allEven += map[i]
        }else{
            if(map[i] > maxOdd){
                // 如果大于最大奇数，则累加上一个最大奇数-1 
                // 并替换最大奇数
                allEven += (maxOdd > 0 ? maxOdd : 1) - 1
                maxOdd = Math.max(map[i], maxOdd)
            }else{
                allEven += map[i] - 1
            }
        }
    }
    return allEven + maxOdd
};
```