```
/**
 * @param {string} s
 * @return {number}
 */

const mapping = {
    "I": 1,
    "V": 5,
    "X": 10,
    "L": 50,
    "C": 100,
    "D": 500,
    "M": 1000,
}

var romanToInt = function(s) {
    
    let res = 0
    let index = 0
    
    while(index<s.length) {
        const curr = mapping[s[index]]
        const next = mapping[s[index+1]]
        if (!next) {
            res += curr
            break
        }
        if (curr >= next) {
            res += curr
            index += 1
        } else {
            res += (next-curr)
            index += 2
        }
    }
    
    return res
    
};
```
