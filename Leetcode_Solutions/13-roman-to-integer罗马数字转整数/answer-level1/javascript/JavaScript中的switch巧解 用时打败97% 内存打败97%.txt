![微信图片_20191026124146.png](https://pic.leetcode-cn.com/708fc479182baa5a1958dfb133d5ed0b1d5e90bb8e1f520fc9ca4603ced3e4a1-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20191026124146.png)

采取switch将特殊情况识别出来
```
var romanToInt = function(s) {
    let obj = {
        I : 1,
        V : 5,
        X : 10,
        L : 50,
        C : 100,
        D : 500,
        M : 1000
    },
        res = 0;
    
    for(let i = 0; i < s.length ;i++){
        switch(s[i]){
            case 'I' : switch(s[i+1]){
                        case 'V' : res += 4; i++; break;        // 因为这种情况下会将当前位置和后一个位置的字符合并在一起读取数值，所以i++
                        case 'X' : res += 9; i++; break;        // 同理
                        default  : res += 1;
                    };break;

            case 'X' : switch(s[i+1]){
                        case 'L' : res += 40; i++; break;
                        case 'C' : res += 90; i++; break;
                        default  : res += 10; 
                    };break;

            case 'C' : switch(s[i+1]){
                        case 'D' : res += 400; i++; break;
                        case 'M' : res += 900; i++; break;
                        default  : res += 100; 
                    };break;
            default : res += obj[ s[i] ];
        }                                 
    }
    return res;
    };
```
