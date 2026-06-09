### 解题思路
运用递归依次剔除`复杂类型hashMap1`和`简单类型hashMap2`

### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */
var romanToInt = function(s) {
    var hashMap1 = {
        'CM': 900,
        'CD': 400,
        'XC': 90,
        'XL': 40,
        'IX': 9,
        'IV': 4
    };
    var hashMap2 = {
        'M': 1000,
        'D': 500,
        'C': 100,
        'L': 50,
        'X': 10,
        'V': 5,
        'I': 1
    };
    var num = 0;
    var recur = (s) => {
        if(s.length !== 0) {
            [hashMap1, hashMap2].forEach(hashMap => {
                for(var key in hashMap) {
                    if(s.includes(key)) {
                        num += hashMap[key];
                        s = s.replace(key, '');
                    }
                }
            });
            recur(s);
        }
    };
    recur(s);
    return num;
};
```