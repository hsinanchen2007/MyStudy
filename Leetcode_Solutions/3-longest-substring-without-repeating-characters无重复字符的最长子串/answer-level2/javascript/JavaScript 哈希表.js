### 解题思路
首先考虑鉴定重复字符，应当使用哈希表来建立所有字符的索引;
然后我们设定一个队列，保存从字符开始到现在所存在的所有非重复子字符串，并实时测量长度和最大值进行比较，更新最大长度；
然后我们考虑如何保证这个队列都是非重复字符串和更新哈希表的问题。如果想保证队列都是非重复字符串，根据哈希表遍历字符串，如果哈希表中已经存在当前字符，则把上一个重复字符及重复字符之前的所有字符都从队列中丢弃，然后把当前字符存储进去，这样就保证队列中都是非重复字符。同时也要更新哈希表，将上一个重复字符及重复字符之前的所有字符的哈希值置空，保证哈希表是当前队列的所有哈希值。
由于我们不需要最长非重复字符串，只需要长度，所以队列可以由两个值代替，一个是队列开头的索引值，一个是队列末尾值，也就是当前字符的索引值。
### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) {
    //如果长度为1或者0,返回此长度
    if(s.length === 0 || s.length === 1) return s.length;
    //max存储处理过程中不含重复字符的最大值,start为不重复字符串的起始索引值,该索引值=数组索引值+1,为了if判断方便
    var max = 1,start = 1;
    //存储所有当前未重复字符位置的哈希表,每个字母都去判断是否前面已经存在位置,如果冲突,则清除上一个字符之前的所有字符,不冲突则存储该位置
    var hashArr = [];
    //遍历处理每一个字符
    for(var i = 0; i < s.length; i++){
        //如果当前字符在之前已经存在
        if(hashArr[s.charCodeAt(i)]){
            //计算从start到当前重复字符的距离
            max = max > (i + 1 - start) ? max : (i + 1 - start);
            //将该字符上一个重复字符之前的所有字符清空,保证现有hash表没有重复字符索引
            for(var j = start; j < hashArr[s.charCodeAt(i)]; j++){
                hashArr[s.charCodeAt(j-1)] = 0;
            }
            //设置start为上一个重复字符
            start = hashArr[s.charCodeAt(i)] + 1;
        }
        else{
            //计算从start到当前未重复字符的距离
            max = max > (i + 2 - start) ? max : (i + 2 - start);
        }
        //存储当前字符索引
        hashArr[s.charCodeAt(i)] = i + 1;
    }
    return max;
};
```