### 解题思路
结题思路：找到是否有连续相同的字符，纪录相同的次数，并且每次索引加1。
![image.png](https://pic.leetcode-cn.com/3e38ed54448f08f49ce314c98ec7eef41797814b76b905220b453304e0b30345-image.png)

### 代码

```javascript
/**
 * @param {string} S
 * @return {string}
 */
var compressString = function (S) {
    var resStr = "", num = 1;
    for (var i = 0; i < S.length;) {
        if (S[i] === S[i + 1]) {
            num++;
        } else {
            resStr += S[i] + num;
            num = 1;
        }
        i++;
    }
    if (resStr.length >= S.length) return S;
    return resStr;
};
```