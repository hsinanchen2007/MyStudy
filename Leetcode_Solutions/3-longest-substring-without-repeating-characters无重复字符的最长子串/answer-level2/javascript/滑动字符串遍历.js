### 解题思路
如果传入的是空字符串可以直接返回0
接下来设置当前选中的非重复字符串长度为cur，最长不重复字符串为result
遍历字符串，
如果能在当前字符串里出现就拼接后把重复出现的第一位去掉
如果没出现则拼接字符串，比较cur和result长度决定是否更新result值

### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) {
    if(!s)return 0;
    let cur=[s[0]];
    let result=[s[0]];
    for(let i=1;i<s.length;i++){
        if(cur.indexOf(s[i])<0){
            cur += s[i]
            if(cur.length>result.length){
                result=cur;
            }
        }else{
            cur += s[i]
            cur = cur.slice(cur.indexOf(s[i])+1);
        }
    }

   return result.length;
    
};
```