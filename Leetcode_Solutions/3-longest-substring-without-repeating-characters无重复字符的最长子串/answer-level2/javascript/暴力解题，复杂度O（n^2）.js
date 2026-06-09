### 解题思路
此处撰写解题思路
设两个变量分别储存最新的子字串和最终长度，双循环遍历，第一层遍历中将首字符放到curstr中，在第二层遍历中进行查找，如果curstr不包含此字符串
则加入进去，如果包含，则结束此次循环，将curstr的长度和最终长度进行对比，如果超过了最终长度则覆盖，然后清除字符串重新进行循环。
### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function (s) {
    let curStr = '' // 当前子字串
    let resLen = 0  // 最终长度
    for (let i = 0; i < s.length; i++) {
        curStr = s[i]
        for (let j = i + 1; j < s.length; j++) {
            if (curStr.includes(s[j])) {
                break
            }
            curStr += s[j]
        }
        if (curStr.length > resLen) {
            resLen = curStr.length
        }
        curStr = ''
    }
    return resLen
};
```