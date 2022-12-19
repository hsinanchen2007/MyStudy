### 解题思路

正则替换很方便

### 代码

```javascript
/**
 * @param {string} S
 * @return {string}
 */
var compressString = function(S) {
    let reg = /([a-zA-Z])\1*/g;//匹配单个或连续出现的字母
    let s = S.replace(reg,(...[content,$1])=>{
        //content为匹配到的整个字符串，如"aaaa"，$1为正则中括号小分组匹配结果，如a
        return $1+content.length;
    })
    if(s.length < S.length) return s;
    if(s.length >= S.length) return S;
    
};
```

> 执行用时 :80 ms 在所有 JavaScript 提交中击败了35.00%的用户
> 内存消耗 :42.9 MB, 在所有 JavaScript 提交中击败了100.00%的用户