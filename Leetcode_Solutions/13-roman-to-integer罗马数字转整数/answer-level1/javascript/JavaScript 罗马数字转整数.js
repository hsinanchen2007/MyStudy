解一：
> `switch`判断每一位的字母，当字母为`I`, `X`, `C`中之一时判断下一位字母与之结合是否符合特殊情况。

```js
var romanToInt = function (s) {
    var re = 0;
    for (var i = 0; i < s.length; i++) {
        switch (s[i]) {
            case 'M':
                re += 1000;
                break;
            case 'D':
                re += 500;
                break;
            case 'C':
                if (s[i + 1] == 'D') {
                    re += 400;
                    i++;
                } else if (s[i + 1] == 'M') {
                    re += 900;
                    i++;
                } else {
                    re += 100;
                }
                break;
            case 'L':
                re += 50;
                break;
            case 'X':
                if (s[i + 1] == 'L') {
                    re += 40;
                    i++;
                } else if (s[i + 1] == 'C') {
                    re += 90;
                    i++;
                } else {
                    re += 10;
                }
                break;
            case 'V':
                re += 5;
                break;
            case 'I':
                if (s[i + 1] == 'V') {
                    re += 4;
                    i++;
                } else if (s[i + 1] == 'X') {
                    re += 9;
                    i++;
                } else {
                    re += 1;
                }
                break;
        }
    }
    return re;
};
``` 

解二：
> 将特殊情况替换为其他字母表示，相当于拓展字母表。并将`switch`条件判断改为映射。缺点是内存占用较大。

```js
var romanToInt = function (s) {
    s = s.replace('IV', 'Q');//4
    s = s.replace('IX', 'W');//9
    s = s.replace('XL', 'E');//40
    s = s.replace('XC', 'R');//90
    s = s.replace('CD', 'T');//400
    s = s.replace('CM', 'Y');//900
    var map = {
        "I": 1,
        "V": 5,
        "X": 10,
        "L": 50,
        "C": 100,
        "D": 500,
        "M": 1000,
        "Q": 4,
        "W": 9,
        "E": 40,
        "R": 90,
        "T": 400,
        "Y": 900,
    }
    var re = 0;
    for (var i in s) {
        re += map[s[i]]
    }
    return re;
};
```
解三：
> 相当于在解一的基础上进行改进，当上一位字母对应数值小于当前字母对应数值时则出现了特殊情况。

```js
var romanToInt = function (s) {
    var map = {
        "I": 1,
        "V": 5,
        "X": 10,
        "L": 50,
        "C": 100,
        "D": 500,
        "M": 1000,
    }
    var re = map[s[0]];
    for (var i = 1; i < s.length; i++) {
        if (map[s[i-1]] >= map[s[i]]) re += map[s[i]]
        else re += map[s[i]] - 2*map[s[i-1]];
    }
    return re;
};
```