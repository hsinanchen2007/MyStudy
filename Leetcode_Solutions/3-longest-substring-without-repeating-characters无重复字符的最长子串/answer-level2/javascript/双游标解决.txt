### 解题思路

1. 大体思路：通过左右两个游标的移动，确定当下字符串是什么，通过preStr随着游标的移动来得到当下移动得到的字符串
2. 更新策略，下一个字母没有重复的时候且字符串长度比保存的maxStr更长，保存当下的字符串加上后一个字母组成的新字符串并右游右移动。如果重复了 左游标移动，不更新右游标。

### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) {
    let leftPoint = 0, rightPoint = 0, preStr = "", maxStr = "";

    while(rightPoint < s.length) {
        preStr = s.slice(leftPoint, rightPoint)
        const nextLetter = s[rightPoint];
        const isRepeat =  preStr.indexOf(nextLetter) !== -1;
        !isRepeat && preStr.length + 1 > maxStr.length && (maxStr = prevStr + nextLetter);

        if(isRepeat) {
            leftPoint++;
        } else {
            rightPoint++;
        }
    }
    return maxStr.length
};
```