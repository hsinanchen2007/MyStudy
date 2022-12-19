这道题在今天晚上做的时候出了很多BUG，由于很久没做过算法题，对于边界条件都忘了很多。导致前期的代码提交一直错误。
- 判断空数组  --->涉及怎样判断空数组(.length)
- 判断数组里面只有一个的情况
- 判断数组里面有多个的情况
    + for循环遍历
```
var longestCommonPrefix = function(strs) {
        if(strs.length ==0){
            return ""
        }else if(strs.length == 1){
            return strs[0]
        }else{
            let firstStrs = strs[0]
            let result = ''
            for(var i=0;i<firstStrs.length;i++){
                for(var j=1;j<strs.length;j++){
                    if(firstStrs[i]!=strs[j][i])
                        return result
                }
                result+=firstStrs[i];
            }
            return result;
        }
    };
```