### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstringTwoDistinct = function(s) {
    // 三指针，第一个指向开始，第二个指向第二个字符，第三个指向末尾
    // 有新的字符，第一个指向第二个，第二个指向第三个，第三个向后继续遍历并算max
    let p1 = 0;
    let p2 = 0;
    let word1 = s[0];
    let word2 = "";
    let max = 0;
    for(let i = 1; i < s.length; i++) {
        if(s[i] != word1 && word2 == "") {
            word2 = s[i];
            p2 = i;
            continue;
        }
        if(s[i] != word1 && s[i] != word2) {
            //console.log(p1, p2, i, word1, word2, s, max)
            max = Math.max(max, i-p1);
            p1 = p2;
            i = p2;
            word1 = word2;
            word2 = "";
            //console.log(p1, p2, i, word1, word2, s, max)
        }
    }
    if(p1 != s.length-1) {
        max = Math.max(max, s.length-p1);
    }
    if(max == 0 && s.length > 0) {
        max = s.length;
    }
    return max;
};
```