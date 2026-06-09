```
var reverseStr = function(s, k) {
    // 循环
    var str = ''
    // 第一部分(整数倍循环部分)
    for(var i=0; i<s.length; i++){
        if(s.length >= i*2*k){
            str += s.substr(2*i*k, 2*k).substr(0, k).split('').reverse().concat(s.substr(2*i*k, 2*k).substr(k).split('')).join('')
        }else{
            sRemain = s.substr(i*2*k)
        }
    }
    // 第二部分（整数倍循环剩余部分）
    if (sRemain.length<k) {
        return str.split('').concat(sRemain.split('').reverse()).join('') 
    } else if (sRemain.length>=k && sRemain.length<2*k) {
        return str.split('').concat(sRemina.substr(0, k).split('').reverse().concat(sRemain.substr(k).split(''))).join('')
    } else {
        return str
    }
};		
```
- 执行用时 :72 ms, 在所有 javascript 提交中击败了89.17%的用户
- 内存消耗 :37.6 MB, 在所有 javascript 提交中击败了45.45%的用户
- 整数倍循环加处理循环剩余字符串，基本上就是按照题目思路来的。另外主要用了js内置API
