### 解题思路
遍历字符串，记录当前不重复字符串的起始下标。
然后比对当前字符串是否存在于，当前坐标-起始下标中。
如果存在，那么修改其实下标
如果不存在，那么累加

### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) {
    if(s.length == 0) return 0;
    if(s.length == 1) return 1;
    var max = 0;
    var sliceIdx = 0;
    for(var i = 0,l = s.length; i<l;i++){
        var idx = s.indexOf(s[i], sliceIdx);
        if(idx == -1 || idx >= i){
            max = Math.max(max, i - sliceIdx)
        }else{
            sliceIdx = idx + 1;
        }
    }
    return max + 1
};
```