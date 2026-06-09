首先利用`sort`的排序方法将数组按照编码排序，只需要校验`array[0]`和`array[array.length-1]`的值。  
然后判断是否存在包含关系即`array[0]`包含于`array[array.length-1]`  
最后对首尾两个值进行字符串匹配，得到公共前缀
  

```JavaScript
/**
 * @param {string[]} strs
 * @return {string}
 */
var longestCommonPrefix = function(strs) {
    strs.sort()//按编码排序
    if (strs.length === 0) return ''//空数组返回''
    var first = strs[0],
        end = strs[strs.length - 1]
    if(first === end || end.match(eval('/^' + first + '/'))){
        return first//first包含于end返回first
    }
    for(var i=0;i<first.length;i++){
        if(first[i] !== end[i]){
            return first.substring(0,i)//匹配失败时返回相应字符串
        }
    }
};
```