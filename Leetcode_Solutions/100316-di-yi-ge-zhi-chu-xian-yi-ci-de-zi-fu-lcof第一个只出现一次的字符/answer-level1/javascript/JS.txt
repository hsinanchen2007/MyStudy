### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string} s
 * @return {character}
 */
var firstUniqChar = function(s) {
    for (let i = 0; i<s.length; i++){
        if (s.lastIndexOf(s[i]) == s.indexOf(s[i])){
            return s[i];
        }

    }
    return " ";
        
};
```