注意输入字符串有大小写字母，还有数字等。
这里替代元音用的‘-1’。


```javascript []
var reverseVowels = function(s) {
    if(s.length<2) return s;
  
    var arr = s.split('');
    var yuan = [];
    var newarr  = arr.map( function(x){
        if(/[aeiouAEIOU]/.test(x)){
            yuan.push(x);
            return '-1';
        }else{
            return x;
        }
    });

    for(var i in newarr){
        if(newarr[i] == '-1'){
            newarr[i] = yuan.pop();
        }
    }

    return newarr.join('');
    
    
};
```
