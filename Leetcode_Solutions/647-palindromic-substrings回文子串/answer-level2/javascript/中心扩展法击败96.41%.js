一开始用了**暴力法**，挨个循环遍历，简单的测试用例都通过了，抱着一丝侥幸提交上去看看能不能通过，果不其然卡在最后一道超长的用例上，超时了
于是只好想更简单，更高效的方法，遂想起求最长回文子串的时候用过的中心扩展法，果然秒过最后一道用例，提交上去击败96.41%的用户，美滋滋。
话不多说，上代码。
```
var countSubstrings = function(s) {
    let len = s.length;
    if (len < 2) return len;
    let result = 0;
    const centerSpread = function (str, left, right) {
        let len = str.length;
        let i = left;
        let j = right;
        while (i >= 0 && j < len) {
            if (str.charAt(i) === str.charAt(j)) {
                result++;
                i--;
                j++;
            } else {
                break;
            }
        }
    };
    for (let i = 0; i < len; i++) {       
        centerSpread(s, i, i);
        centerSpread(s, i, i + 1);
    }
    return result;
};
```
