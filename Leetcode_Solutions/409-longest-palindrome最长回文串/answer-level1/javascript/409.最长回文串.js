### 解题思路
1. 统计字符串中各个字符出现的次数(strMap)
2. 遍历strMap
    2.1 如果字符出现偶数次，那么一定可以构成回文字符串的一部分，直接累加字符的长度即可
    2.2 如果字符都出现奇数次，那么将字符出现的次数减去一，使它出现的次数为偶数次，然后加起来
    2.3 因为回文字符串的长度可以为奇数，当字符串中存在出现奇数次的字符时，需要将结果加1，表示为最中间的字符


### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */
var longestPalindrome = function(s) {
    let ans = 0;
    let odd = false;
    let strMap = {};
    for(let i=0;i<s.length;i++){
        if(s[i] in strMap){
            strMap[s[i]] += 1;
        } else {
            strMap[s[i]] = 1;
        }
    }
    
    for(let key in strMap) {
        if(strMap[key] % 2 === 0) {
            ans += strMap[key];
        } else {
            odd = true;
            ans += strMap[key]-1;
        }
        
    }
    if(odd) {
        ans+=1;
    }
    return ans;
};
```