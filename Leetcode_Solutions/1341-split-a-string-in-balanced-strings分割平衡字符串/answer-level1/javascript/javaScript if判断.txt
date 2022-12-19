var balancedStringSplit = function(s) {
    var z = '';     //装s的每个值的索引
    var strR = 0;   //装出现R的次数
    var strL = 0;   //装不是R的次数
    var num = 0;    //装分割次数
    for(var i = 0;i < s.length;i++){    //所有值的索引
        z = s[i];                       //把s的i索引值赋予z
        if(z ==='R'){                   //如果z值有'R'
            strR++                      //strR会叠加一次
        }else{                          //如果不是
            strL++                      //strL会叠加
        }   
        if(strL===strR){                //strL和strR次数一样
            num++;                      //分割次数叠加一次
            strL=0;                     //strR叠加清0
            strR=0;                     //strL叠加清0
        }
    }
    return num                          //返回分割次数
};