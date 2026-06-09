
# 通过两重循环求解的简单方法

求解的思路如下：根据题意，我们要找到最长的公共前缀，也就是说我们可以以列表中的第一个字符串为基础，
然后对该字符串进行遍历，从该字符串的第0位开始，让输入列表中的其他字符串都分别与第一个字符串的第0
位字符串相比较。如果比较结果出现不同时，也就是出现了列表中的字符串第i位出现差异。因此第i位之前的
字符串即为公共前缀。
```
var longestCommonPrefix = function(strs) {
    let re='';
    if(strs.length===0){
        return re;
    }
    let flag=false;
    for(var i=0;i<strs[0].length;i++){
        for (var j=1;j<strs.length;j++){
            if(strs[j][i]!=strs[0][i]){
                flag=true;
                break;
            }
        }
        if(flag){
            break;
        }
   }
    return re+strs[0].slice(0,i);

   
};
```
