*法一：switch语句，特殊处理以“I、X、C”开头的字符*
```js
var romanToInt = function(s) {
    var result = 0;
    var len = s.length;
    for( let i = 0; i < len; i++) {
        switch(s[i]) {
            case 'I':
                if (s[i + 1] === 'V') {
                    result += 4;
                    i++
                } else if (s[i + 1] === 'X') {
                    result += 9;
                    i++
                } else {
                   result += 1; 
                }
                break;
            case 'V':
                result += 5;
                break;
            case 'X':
                if (s[i + 1] === 'L') {
                    result += 40;
                    i++
                } else if (s[i + 1] === 'C') {
                    result += 90;
                    i++
                } else {
                   result += 10; 
                }
                break;
            case 'L':
                result += 50;
                break;
            case 'C':
                if (s[i + 1] === 'D') {
                    result += 400;
                    i++
                } else if (s[i + 1] === 'M') {
                    result += 900;
                    i++
                } else {
                   result += 100; 
                }
                break;
            case 'D':
                result += 500;
                break;
            case 'M':
                result += 1000;
                break;
            default:
                result += 0;
                break;
        }
    }
    return result;
}
console.log(romanToInt(s))
```

*法二：将两位罗马数字转成一位*
```js
var romanToInt2 = function(s) {

    s = s.replace(/IV/g, 'Q'); //4
    s = s.replace(/IX/g, 'W'); //9
    s = s.replace(/XL/g, 'E'); //40
    s = s.replace(/XC/g, 'R'); //90
    s = s.replace(/CD/g, 'T'); //400
    s = s.replace(/CM/g, 'Y'); //900
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
    };
    var len = s.length;
    var result = 0;
    for(var i in s) {
        result += map[s[i]]
    }
    return result
}

console.log(romanToInt2(s))
```


