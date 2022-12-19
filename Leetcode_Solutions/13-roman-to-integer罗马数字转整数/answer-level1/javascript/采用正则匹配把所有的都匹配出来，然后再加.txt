### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */
var romanToInt = function(s) {
    const obj={
        'I':1,
        'V':5,
        'X':10,
        'L':50,
        'C':100,
        'D':500,
        'M':1000,
        'IV':4,
        'IX':9,
        'XL':40,
        'XC':90,
        'CD':400,
        'CM':900
    }
    const res = s.match(/IV|IX|XL|XC|CD|CM|I|V|X|L|C|D|M/g)
        .reduce((total,i)=>{return total+obj[i]},0)
    return res
};
```