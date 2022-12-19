## 方法一
### 解题思路：
1.长度是单数的直接返回false。
2.每个括号定义有值， 正负刚好可以抵消。 遇到正向括号"({["就记录在数组arr里面。
3.一遇到负向括号"]})",便开始判断 arr最后一个值是不是与当前匹配的一对，是则开始抵消，不是 则证明顺序是错的。直接输出false。
4.最后输出 是否完全抵消完毕的布尔值。


```
var isValid = function(s) {
    if(s.length%2)return false; //长度是单数的 直接false
    let obj = {
        '(':1,
        ')':-1,
        '{':2,
        '}':-2,
        '[':3,
        ']':-3
    }

    // 用于记录正向值
    let arr = [];
    for(let i=0;i<s.length;i++){
        if(obj[s[i]] > 0){ //大于0的都装在数组里面
            arr.push(obj[s[i]]);
        }else{
            //当前要做减法的这项 是不是与arr最后一个值 是匹配的一对？
            if(Math.abs( obj[s[i]] ) == arr[arr.length-1] ){ 
                arr.pop(); //因为永远都是从最后面开始相减 所以直接用pop就可以了 不需要用splice
            }else{
                return false;//没有按顺序
            }
        }
    }
    // 长度为0 代表全抵消完则true
    return !Boolean(arr.length)
};
```

## 方法二
### 解题思路：
1.利用正则 循环抵消() {} [] 完整的组合。
2.结束后判断是否完全抵消完毕
```
var isValid = function(s) {
    if(s.length%2)return false; //长度是单数的 直接false

    let stop = false;
    while(!stop){
        var reg = new RegExp(/(\(\)|\[\]|\{\})+/,"g")
        if(reg.test(s) && s.length){ 
            s = s.replace(reg,"");
        }else{
           stop = true;
        }
    }
    // 长度为0 代表全抵消完则true
    return !Boolean(s.length)
};
```
