
# 解题思路： 所有字符都是偶个数 + 中间一个单独奇数的 才能组成最大回文串；

1、累计所有偶个数的字符总个数
2、判断是否还剩字符没累计，如果有 +1

```
var longestPalindrome = function(s) {
    var countObj = {};
    var res = 0;//最大
    for(var i=0;i<s.length;i++){
        if(!countObj[s[i]]){
            countObj[s[i]] = 1;
        }else{
            res +=2; 
            delete countObj[s[i]];
        }
    }
    if(s.length > res){ //剩余存在奇个数字符
        res +=1;
    }
    return res;
};
```
