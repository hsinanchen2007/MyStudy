### 解题思路
看代码

### 代码

```javascript
/**
 * @param {string} s
 * @return {character}
 */
var firstUniqChar = function(s) {
    const map = {}
    for(let i of s){
        map[i] = (map[i] || 0) + 1;
    }
    for(let i in map){
        if(map[i] == 1){
            return i
        }
    }

    return " "
};
```