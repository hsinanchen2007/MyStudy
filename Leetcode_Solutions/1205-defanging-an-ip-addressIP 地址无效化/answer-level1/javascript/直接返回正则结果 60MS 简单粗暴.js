题目要求将所有的 . 转换为 [.]
直接用replace+正则表达式匹配即可
# 代码如下
```javascript []
var defangIPaddr = function(address) {
    return address.replace(/\./g,'[.]')   
};
```
`obj.replace()`//替换
`(/\./g)`//替换规则——匹配字符串 "."
`(,'[.]')`//替换为什么内容——"[.]"
简单粗暴，但不应用于所有场景

