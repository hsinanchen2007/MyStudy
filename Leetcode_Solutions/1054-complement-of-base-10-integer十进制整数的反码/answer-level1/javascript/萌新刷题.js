# 萌新刷题,有错误请改正,谢谢.
```
var bitwiseComplement = function(N) {
    let temp = N.toString(2);               // 给数转换成二进制
    let y = []                              // 创建一个空数组
    for(let i = 0; i < temp.length; i++){   //循环找到temp的所有索引
        let x = temp.split('')              // 给字符串转换成数组形式
        if(x[i] == 0){                      // 判断是否为0
            x[i] = 1;                       // 值变为0    
            y[i] = x[i];                    // 给空数组添加值 [empty,1]
        }else if(x[i] == 1){                // 判断是否为
            x[i] = 0;                       // 值变为0
            y[i] = x[i];                    // 给空数组添加值 [0,1,0]
        }
    }
    let z =  y.join('')                     // 转换成字符串
    return parseInt(z,2);                   // 输出010
```

