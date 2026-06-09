先计算字符串中各个字符出现的次数，再用数据排序，最后字符拼接输出结果
```js
var frequencySort = function(s) {
    var map = new Map();
    for(var i=0;i<s.length;i++){
        if(map.has(s[i])){
            map.set(s[i], map.get(s[i])+1);
        }else{
            map.set(s[i], 1);
        }
    }
    var arr = [];
    map.forEach((v, k)=>arr.push({name: k, value: v}));
    arr.sort((a,b)=>b.value-a.value);
    var res = '';
    for(var i=0;i<arr.length;i++){
        var temp = arr[i].name;
        var c = arr[i].value;
        for(var j=0;j<c;j++){
            res += temp;
        }
    }
    return res;
};
```