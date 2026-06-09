### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string} s
 * @return {character}
 */
var firstUniqChar = function(s) {
    var res =" ";
    for(var i =0;i< s.length;i++){
        if(s.indexOf(s[i])==s.lastIndexOf(s[i])){
            res = s[i];
            break;
        }
    }
    return res;
};
```