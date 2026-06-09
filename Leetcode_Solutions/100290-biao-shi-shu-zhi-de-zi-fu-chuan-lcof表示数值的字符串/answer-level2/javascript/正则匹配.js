献丑 给大家参考下；最开始想一口吞一个大象 直接return一条正则。 
恶心的零碎越来越多 于是静下心分开一条条规则分开写：
- 普通不含e的 ： /^[\+\-]?(\d*\.?\d*)$/i.test(s);
- 含e且之后跟加减的 ： return /^[\+\-]?((\d+\.?\d*)|(\d*\.?\d+))e[\+\-]\d+$/i.test(s)
- 含e没加减的  ：  return /^[\+\-]?((\d+\.?\d*)|(\d*\.?\d+))e\d+$/i.test(s)

当终于有提交成功之后 回看发现可以合并就 第2和3是可以合并的。
目前剩的两条 继续搞的话 其实应该也是可以合并成一条的。 

还是有很多优化空间的

```
var isNumber = function(s) {
    var point = s.match(/\./g);
    if((point && point.length>1) || !/\d/.test(s)){
        return false;
    }
    s = s.replace(/^\s*|\s*$/g,"");   //消除前后空格
    
    if(!/e/i.test(s)){  //不含e的: 正负+整数+点+小数随意搭配 
        return /^[\+\-]?(\d*\.?\d*)$/i.test(s); 
    }else{              //含e的: 正负+ (整数+点+小数) 随意搭配 +e+ 正负可带可不带+ 数字一定要带  
        return /^[\+\-]?((\d+\.?\d*)|(\d*\.?\d+))e[\+\-]?\d+$/i.test(s)
    }
    return false;
};
```
