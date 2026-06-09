### 解题思路
此处撰写解题思路
    首先判断目标数组是否为空，若为空，则 返回 "";
    判断数组内是否只有一个字符串，若是，则返回 当前字符串；
    `subIndex` 为 当前前缀索引， `commonStartStr`  为公共前缀；外层 while 循环判断 公共子串或 前缀索引值 是否已经超出第一个字符串的长度，若超出则结束循环；
    内层循环判断当前 字符串 是否以公共子串开头，若是则 index++ ,判断下一个字符串，若不是则结束循环， falg 置为false;
    内层换换结束后 判断 flag 是否为 true
### 代码

```javascript
/**
 * @param {string[]} strs
 * @return {string}
 */
var longestCommonPrefix = function(strs) {
    if(strs.length<1) return "";
    if(strs.length==1) return strs[0]
    let firstStr = strs[0]
    let subIndex = 1
    let commonStartStr = firstStr.substring(0, subIndex)
    if (!commonStartStr) return ''
    while (firstStr.length >= commonStartStr.length && subIndex <= firstStr.length) {
        let index = 1;
        let flag = true
        while (index < strs.length && flag) {
            let currentStr = strs[index]
            if (!currentStr.startsWith(commonStartStr)) {
                flag = false
                break;
            }
            index++;
        }
        if (flag) {
            subIndex++;
            commonStartStr = firstStr.substring(0, subIndex)
        } else {
            commonStartStr = firstStr.substring(0, subIndex - 1)
            break;
        }

    }
    return commonStartStr ? commonStartStr : ''
};
```