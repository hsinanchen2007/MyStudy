### 解题思路
![image.png](https://pic.leetcode-cn.com/5da1e024aa0676a9556b50f2ed31a43d635edd560420c50ef38dc3131653ba3a-image.png)
很简单的思路，几行代码，一看就会啦~

### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) {
    const len = s.length;
    let res = 0;
    let temp = '';
    for(let i = 0; i < len; i ++) {
        if(temp.indexOf(s[i]) === -1) {
            temp += s[i];
            res = Math.max(res, temp.length);
        } else {
            temp = temp.slice(temp.indexOf(s[i]) + 1);
            temp += s[i];
        }
    }
    return res;
};
```