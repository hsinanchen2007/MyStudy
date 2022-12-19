### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isIsomorphic = function(s, t) {
    for(var i=0;i<s.length;i++) {
        if(s.indexOf(s[i])!=t.indexOf(t[i])){
            return false;
        }
    }
    return true;
};

```