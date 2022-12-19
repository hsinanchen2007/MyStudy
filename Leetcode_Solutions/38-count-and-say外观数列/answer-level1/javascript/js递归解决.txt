思路：用的递归思想，观察发现每一个结果和前一个结果有关，出口是第一个报数，主要是那个正则的想法

```
var countAndSay = function(n) {
    if(n==1){
        return n.toString()
    }
    var tempArr = countAndSay(n-1).match(/(\d)\1*/g)  // 该正则进行相同分组，调用match方法得出接下来用的数组
    var result = ""
    tempArr.forEach((item)=>{              // 循环上面得到的数组，然后取每个的长度（题里说的几个），还有第一个数字（题里说的哪个数）
        var lth = item.length.toString()
        var num = item.substring(0,1)
        result = result+lth+num
    })
    return result   //最后返回结果
    
};
```

递归真是神奇
