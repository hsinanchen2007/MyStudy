# 解题思路
创建一个长度和一个新的字符串
当字母不存在则拼接起来，并且实时获取最长的字符串的长度，当遇到重复的情况字母则获取索引值并且对字符串进行截取。
```
var lengthOfLongestSubstring = function(s) {
    let len = 0;
    let val = '';
    for(let i = 0; i < s.length; i++){
        if(val.indexOf(s[i]) === -1){
            val = val + s[i];
            if(val.length > len){
                len = val.length;
            }
        }else{
            val = val + s[i];
            let index = val.indexOf(s[i]);
            val = val.slice(index + 1);
        }
    }
    return len;
};
```
