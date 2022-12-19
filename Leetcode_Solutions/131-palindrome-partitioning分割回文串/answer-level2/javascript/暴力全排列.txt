
```
//类似全排列，不断的扩充数组，如“acab”,[['a']]=>[['ab'],['a','b']]=>[['ab','c'],['a','b','c'],['abc'],['a','bc']]......
//新的内容添加入数组有两种情况：追加到之前的数组中成为单独的一项、追加到之前数组的最后一项末尾
//当第一种情况时，只有原数组最后一项是回文串时才可能是一种分解情况的一部分（去掉不符合的情况）
var partition = function(s) {
    if(s.length==0)
        return [[]];
    var res=[[s[0]]];
    for(var i=1;i<s.length;i++){
        var len=res.length;
        for(var ii=0;ii<len;ii++){
            if(pd(res[ii][res[ii].length-1])){
                res.push([...res[ii],s[i]]);
                res[ii][res[ii].length-1]+=s[i];
            }else{
                res[ii][res[ii].length-1]+=s[i];
            }
        }
    }
    return res.filter(function(a){
        if(a[a.length-1].length==1)
            return true;
        return pd(a[a.length-1]);
    })
    function pd(str){
        var start=0,
            end=str.length-1;
        while(start<=end){
            if(str[start]!==str[end])
                return false;
            start+=1;
            end-=1;
        }
        return true;
    }
}
```