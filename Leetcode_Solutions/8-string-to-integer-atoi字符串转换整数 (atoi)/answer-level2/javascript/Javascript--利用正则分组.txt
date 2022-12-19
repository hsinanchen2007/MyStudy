正则匹配出分组里的数字, 返回并转成数字;再判断是够有超上下限;

//65.44 52.04
```
var myAtoi = function(str) {
    //正则匹配出来并且*1使它变成是数字；否则默认0
    var num = str.match(/^\s*([\+|\-]?\d+)/)?str.match(/^\s*([\+|\-]?\d+)/)[1]*1:0; 
    var max = 2**31;
    if(num && Math.abs(num) >= max){ //大于限制输出限制
        return (num>=0)?max-1:max*-1;
    }
    return num; 
};

```

--------------------------------
以下是一个比较麻烦的写法 也Mark下

//50.62  53.34
```
var myAtoi = function(str) {
    if(/^\s*[\-|\+]?\d/.test(str) && str.match(/\-?\d+/)!= null){
        var num = str.match(/\-?\d+/)[0];
        if(num < 2**31 && num > -(2**31)){
            return num;
        }else if(num >= 2**31){
            return 2**31 -1;
        }else{
            return -(2**31);
        }
    }else{
        return 0;
    }
};
```
