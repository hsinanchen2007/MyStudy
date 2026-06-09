```
var compress = function(chars) {
    var i=j=0;
    while(i<chars.length && j<chars.length){
        chars[i++]=chars[j];
        var temp=j; //temp存放未压缩字符的首位置
        while(j<chars.length && chars[j]==chars[i-1]){
            j++; //j是未压缩字符的末位置
        }
        var num=j-temp;//同一个字符的个数
        var arr = num.toString(); //个数转化为字符串
        if(num>1){//将个数的每一位存入数组中
            for(var m=0;m<arr.length;m++){
                chars[i++]= arr[m];
            }
        }
    }
    return i;
};
```
