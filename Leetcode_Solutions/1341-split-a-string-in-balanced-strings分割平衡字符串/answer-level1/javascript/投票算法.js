### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */
var balancedStringSplit = function (s) {
    let vote = 1;
    let user = s[0];
    let ans = 0;
    for (let i = 1; i < s.length; i++) {
        if (user === s[i]) {
            vote++;
        } else {
            vote--;
        }
        if (vote === 0) {
            ans++;
        }
    }
    return ans;
};
```