### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */
var romanToInt = function(s) {

    const OBJ = {
        CM: 900,
        CD: 400,
        XC: 90,
        XL: 40,
        IX: 9,
        IV: 4,
        M: 1000,
        D: 500,
        C: 100,
        L: 50,
        X: 10,
        V: 5,
        I: 1
    }

    let value = 0;

    while(s.length > 0) {
        for (let key in OBJ) {
            if (s.indexOf(key) > -1) {
                value += OBJ[key]
                var reg = new RegExp(key)
                s = s.replace(reg,'')
            }
        }
    }

    return value;
};
```