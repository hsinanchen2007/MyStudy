```
var characterReplacement = function(s, k) {
    let start=0//定义滑动窗口的开始
    let dict={}//定义一个哈希对象
    let numRepeatChar=0//重复字符串的长度
    let longestStr=0//最后的输出结果
    //从左到右遍历字符串
    for(let end=0;end<s.length;++end){
        let c1=s[end]
        dict[c1]=dict[c1]||0
        dict[c1]+=1
        numRepeatChar=Math.max(numRepeatChar,dict[c1])
        if(((end-start+1)-numRepeatChar)>k){
            //开始收缩
            dict[s[start]]--
            start++
        }
        longestStr=Math.max(longestStr,(end-start+1))
    }
    return longestStr
};
```
