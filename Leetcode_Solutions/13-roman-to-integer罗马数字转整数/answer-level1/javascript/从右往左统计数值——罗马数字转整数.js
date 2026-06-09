我们习惯性从左往右去看数字，但我觉得这题从右往左来计算会更适合。
比如题目中提到的罗马数字"MCMXCIV"，
假如我们从右往左计算的话，
V = 5，总数我们就先加上5，
I = 1，比上一个数字小，总数就减去1，总数是4
C = 100， 比上一个数字大，总数再加100，是104
X = 10，比上一个数字小，总数减去10，是94
M = 1000，比上一个数字大，总数加上1000， 是1094
C = 100，比上一个数字小，总数减去100， 是994
M = 1000，比上一个数字大，总数加上1000， 是1994

从右往左计算的话，我们就不需要去拼CM还是XC，来一个字符就计算一次，不是加就是减。
```
var romanToInt = function(s) {
    var objRome = {
      "I": 1,
      "V": 5,
      "X": 10,
      "L": 50,
      "C": 100,
      "D": 500,
      "M": 1000
    };
    var count = 0;
    var tmpNum = 0;
    for (var i =s.length -1 ; i >= 0; i--){
        var str = s[i];
        var value = objRome[str];
        if (value){
            if (tmpNum <= value){
                count += value;
            }else{
                count -= value;
            }
            tmpNum = value;
        }else{
            return 0;
        }
    }
    return count;
};
```
