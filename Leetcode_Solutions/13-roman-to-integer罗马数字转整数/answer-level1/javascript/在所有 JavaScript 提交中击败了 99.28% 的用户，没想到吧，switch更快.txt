### 解题思路
这道题不难。没想到的是keyvalue对象比switch查询要慢得多

### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */
var romanToInt = function(s) {
    if (!s) return 0;
    let num = 0;
    s = s.split('');
    while(s.length - 1) {
        if (getValue(s[0]) < getValue(s[1])) {
            num -= getValue(s[0]);
        } else {
             num += getValue(s[0]);
        }
        s.shift();
    }
    num += getValue(s[0]);
    return num;
};

const getValue = (ch) => {
    switch(ch) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0;
    }
}

```