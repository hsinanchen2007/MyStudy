```
/**
 * @param {string} S
 * @return {string}
 */
var removeOuterParentheses = function(S) {
    var cnt = 0;
    var ans = [];
    var last_index = 0;
    for (let i = 0; i < S.length; i++) {
        let ch = S[i];
        if (ch === "(") {
            cnt++;
        } else if (ch === ")") {
            cnt--;
        }
        if (cnt === 0) {
            ans.push(S.substring(last_index, i+1));
            last_index = i+1;
        }
    }
    return ans.map(s => {
        if (s.length === 2) {
            return "";
        } else {
            return s.substring(1, s.length - 1);
        }
    }).join("");
};
```
这样写可能好理解一些。仔细阅读题目描述后，发现可以分步进行：
1. 先对S进行原语化分解，
2. 再删除分解中每个原语字符串的最外层括号

而如何划分原语？观察发现，每当**左右括号的数量相等时**，一个原语可以被划分出来。
于是：
- 用一个变量cnt记录，遇到左括号“(”则递增1，遇到右括号“)”则递减1。
- 变量cnt变0时说明出现了**左右括号数量相等**的情况，此时将该原语摘出，通过取子串的形式，添加到数组ans中。
- 同时记录本次原语划分终点的位置，方便下一次划分时获得原语起点。

当已经将字符串S划分为原语组成的数组ans后，利用map函数对数组ans中的每个元素分别处理。
- 如果长度为2则其是“()”，直接返回空字符串""
- 否则直接删去最外层括号（即第一个和最后一个字符）即可
- 用join函数，以空字符串""作为分隔符，将数组ans连接成字符串并返回
