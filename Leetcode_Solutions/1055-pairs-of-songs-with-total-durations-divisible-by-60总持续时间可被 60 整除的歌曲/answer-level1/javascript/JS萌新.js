萌新入门1个月写的,大佬随便看看就行
```
var numPairsDivisibleBy60 = function(time) {
    var x = 0
    for(var i = 0;i < time.length;i++){
        for(var j = i + 1;j < time.length;j++){
            var arr =  (time[i] + time[j]) % 60 
            if (arr == 0) {
                x++
            }
        }
    }
    return x;
};
```
