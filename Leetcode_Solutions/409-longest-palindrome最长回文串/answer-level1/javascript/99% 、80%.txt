### 解题思路
思路很简单，先生成字典dic，对应每个单词出现的次数

出现偶数，即为回文串 ，所以加上偶数的长度

出现基数，基数 - 1即为偶数，然后加上其长度

结尾判断，是否出现过基数，如果出现过基数，因为我们对每一个基数都-1了，但是最后一个最长的基数可以当回文串中心点使用，所以+1，即补上最长基数

结果就是最长回文串了
### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */
var longestPalindrome = function (s) {
    const dic = s.split('').reduce((t, i, idx) => {
        // if (t[i]) {
        //     t[i]++;
        // } else {
        //     t[i] = 1;
        // }
        t[i] = t[i] ? ++t[i] : 1;// 三目写法
        return t;
    }, {})
    let ans = 0;
    let hasNum = 0;
    Object.entries(dic).map(([k, v]) => {
        if (v % 2 === 0) {
            ans += v;
        } else {
            ans += v - 1; // 每个基数-1即为偶数，不用担心1-1=0，因为会在结尾+1
            hasNum = v;
        }
    })
    if (hasNum) ans++; // 如果存在基数项，就+1 
    return ans;
};
```