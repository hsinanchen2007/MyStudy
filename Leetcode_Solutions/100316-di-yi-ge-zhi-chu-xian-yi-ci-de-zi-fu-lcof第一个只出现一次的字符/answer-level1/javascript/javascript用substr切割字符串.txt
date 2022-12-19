str1是所遍历字符前面所有的字符集合
str2是后面所有字符的集合
若两个都没有就return该字符
```
var firstUniqChar = function(s) {
  for(let i=0;i<s.length;i++){
    let str1=s.substr(0,i);
    let str2=s.substr(i+1);
    if(!str1.includes(s[i])&&!str2.includes(s[i])) return s[i]
  }
  return ' '
};
```
