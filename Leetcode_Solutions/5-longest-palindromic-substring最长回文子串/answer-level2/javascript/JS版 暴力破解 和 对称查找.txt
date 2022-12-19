# 暴力破解
获取所有可能的子串，判断是否是回文
```js
 var longestPalindrome = function(s) {
    var max = '';
    var len = s.length
    if(len < 2) return s;
    for (var i = 0; i <= len; i++) {
        for (var j = 0; j <= len; j++) {
            var child = s.slice(i,j);
            var child_len = child.length;
            var max_len = max.length;
            var arr = child.split('');
            var str1 = arr.join();
            var str2 = arr.reverse().join();
            if(str1 === str2 && max_len < child_len) max = child;
            child = child_len = max_len = arr = str1 = str2 = null
        }
    }
    return max;
};
```
# 对称查找
一核对称:121、12321、1
双核对称:11、1221、123321
先枚举每一个字符，再针对该字符进行左右（双核对称时为当前字符和下一个字符）查找相等匹配
```js
var longestPalindrome = function(s) {
    var max = '';
    var len = s.length
    if(len < 2) return s;
    for (var i = 0; i <= len; i++) {
          var max_new = core(s,len,i)
          max = max_new.length > max.length ? max_new : max;
    }
    return max;
};

function core(str, str_len, str_i){
    var max_1 = loop(str_i-1, str_i+1); // 一核对称 str_len >= 3 str_i = 1
    var max_2 = loop(str_i, str_i+1); // 双核对称 str_len >= 2 str_i = 0
    return max_1.length > max_2.length ? max_1 : max_2;
    
    function loop(pre, next){
        if(!str[pre] || !str[next]) return str.slice(pre+1, next);
        if(str.charAt(pre) === str.charAt(next)) return loop(pre-1, next+1)
        else return str.slice(pre+1, next)
    }
}
```
