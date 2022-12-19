### 自己的代码：冗余、没有利用好题目的性质，虽说自己写的也是贪心算法的思路
```
var intToRoman = function(num) {
    var str = '';
    var thousand, nineHundred, fivHundred, fourHundred, hundred, ninty, fifity, forty, ten, nine, five, four;
    // switch case语句不能使用条件判断，因为switch是 严格等于=== ，且每个case后的判断不能相等
    while(num<4000 && num>0) {
        if(num >= 1000) {
            // js中的除法运算 / 是精确到小数位的，不跟c一样只留上位数，因此需要函数处理
            thousand = Math.floor(num / 1000);
            num = num % 1000;
            while(thousand--) {
                str += 'M';
            }
        } 
        if(num >= 900) {
            nineHundred = 1;
            num -= 900;
            while(nineHundred--) {
                str += 'CM';
            }
        }
        if(num >= 500) {
            fivHundred = Math.floor(num / 500);
            num = num % 500;
            while(fivHundred--) {
                str += 'D';
            }
        }
        if(num >= 400) {
            fourHundred = 1;
            num -= 400;
            while(fourHundred--) {
                str += 'CD';
            }
        }
        if(num >= 100) {
            hundred = Math.floor(num / 100);
            num = num % 100;
            while(hundred--) {
                str += 'C'
            }
        }
        if(num >= 90) {
            ninty = 1;
            num -= 90;
            while(ninty--) {
                str += 'XC'
            }
        }
        if(num >= 50) {
            fifity = Math.floor(num / 50);
            num = num % 50;
            while(fifity--) {
                str += 'L'
            }
        }
        if(num >= 40) {
            forty = 1;
            num -= 40;
            while(forty--) {
                str += 'XL'
            }
        }
        if(num >= 10) {
            ten = Math.floor(num / 10);
            num = num % 10;
            while(ten--) {
                str += 'X'
            }
        }
        if(num >= 9) {
            nine = 1;
            num -= 9;
            while(nine--) {
                str += 'IX'
            }
        }
        if(num >= 5) {
            five = Math.floor(num / 5);
            num = num % 5;
            while(five--) {
                str += 'V'
            }
        }
        if(num == 4) {
            four = 1;
            num -= 4;
            while(four--) {
                str += 'IV'
            }
        }
        while(num--) {
            str += 'I'
        }   
    }
    return str;
};
```
### 大神的代码，简洁、易读性强
1. 暴力法，列举每一位上可能的罗马字母，根据每一个位对应的罗马字母来
```
var intToRoman = function(num) {
    var Q = ["", "M", "MM", "MMM"];
    var B = ["", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"];
    var S = ["", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"];
    var G = ["", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"];
    return Q[Math.floor(num/1000)] + B[Math.floor((num%1000)/100)] + S[Math.floor((num%100)/10)] + G[num%10];
};
```
2. 贪心算法
```
var intToRoman = function(num) {
    var romanArr = ['M', 'CM', 'D', 'CD', 'C', 'XC', 'L', 'XL', 'X', 'IX', 'V', 'IV', 'I']
    var arr = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1]
    var str = ''

    for (var i = 0; i < 13;) {
        if (num >= arr[i]) {
            num -= arr[i]
            str += romanArr[i]
        } else {
            i++
        }
    }
    return str
};
```

