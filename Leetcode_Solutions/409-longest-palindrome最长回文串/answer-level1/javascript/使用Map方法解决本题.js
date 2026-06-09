### 解题思路
此处撰写解题思路

找到每个字母出现的次数，把偶数次直接累加，奇数次-1后累加，如果存在奇数，最大的奇数应全部被累加，故而将刚刚减掉的1加回来。

### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */
var longestPalindrome = function(s) {
   const wordMap = new Map()
    for (let char of s){
        wordMap.set(char, wordMap.has(char)? wordMap.get(char)+1 : 1)
    }
    let n = 0, temp = 0
    for (let value of wordMap.values()){
        if(value % 2 == 0){
            n = n + value
        }else {
            if(value > temp){
                temp = value
            }
            n = n + (value-1)
        }
    }
    if(temp != 0){
        n = n + 1
    }
    return n
};
```