迭代去除退格字符和退格字符前一个字母（可能不存在）
```javascript []
var backspaceCompare = function(S, T) {
   return check(S)===check(T);   
};
var check=function(str){
     while(str.indexOf('#')!=-1)
        str= str.replace(/.?\#/,'');
    return str;
}
```

