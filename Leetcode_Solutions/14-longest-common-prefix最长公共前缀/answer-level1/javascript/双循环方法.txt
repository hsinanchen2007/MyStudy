### 解题思路
- 把数组第一个字符串元素当做基准
- 从头开始检查字母在不在其它元素的相同位置上，如果不在，则返回，若在，将相同的字符拼到公共前缀
- 如果数组为空则直接返回""
### 代码

```javascript
/**
 * @param {string[]} strs
 * @return {string}
 */
var longestCommonPrefix = function(strs) {
    let ans = ''
    let has = true
    if(!strs.length) return ''
    for(let i=0;i<strs[0].length;i++){
        for(let j=1;j<strs.length;j++){
            if(strs[0][i]!=strs[j][i])
            has=false;
            return ans;
        }
        if(has) ans+=strs[0][i];
    }
    return ans
};
```