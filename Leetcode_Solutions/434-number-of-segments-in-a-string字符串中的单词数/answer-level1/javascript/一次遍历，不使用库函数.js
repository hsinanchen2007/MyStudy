### 方法
设置count初始值为0，遍历字符串，只要后一个字符不等于前一个字符，并且后一个字符是空格的情况下，就把count++，为避免字符串最后一个是单词的情况，所以手动在字符串末尾加一个空格，代码如下：
```
var countSegments = function(s) {
    let count = 0;
    s += ' ';
    for (let p = 1; p < s.length; p++){
        if (s[p - 1] !== s[p] && s[p] === ' ') count++;
    }
    return count;
};
```
如有问题，还请指正，谢谢。
