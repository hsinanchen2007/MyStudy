```
var myAtoi = function (str) {
    return Math.max(-2147483648, Math.min(2147483647,(!parseInt(str) ? 0 : parseInt(str))));
};
```
yeah
开心，顺便贴上第一次思路：
```
var myAtoi = function (str) {
    var flag = 0;
    var flagNum = 0;
    for (var i = 0; i < str.length; i++) {
        if (str[i] != ' ') {
            str = str.substr(i, str.length - i);
            if (str[0] == '-' || str[0] == "+") {
                flag++;
            }
            break;
        }
    }
    // console.log("去除空格", str);
    for (var i = 0; i < str.length; i++) {
        //console.log('step:',i,str[i],flag,flagNum)
        if (str[i] == ' ') {
            str = str.substr(0, i);
            break;
        } else if (str[i] * 0 == 0) {

        } else if (str[i] == '-' || str[i] == '+') {
            if (flagNum < flag)
                flagNum++;
            else {
                str = str.substr(0, i);
                break;
            }
        } else {
            str = str.substr(0, i);
            break;
        }
    }
    str = str * 1;
    if (str > 2147483647) {
        return 2147483647;
    } else if (str < -2147483648) {
        return -2147483648;
    } else if (!str) {
        return 0;
    }
    return str;
}
```
