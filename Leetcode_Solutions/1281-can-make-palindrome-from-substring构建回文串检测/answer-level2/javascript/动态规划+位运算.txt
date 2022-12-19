 - dp[i]表示以s的前i-1位结果的 以二进制的形式代表字母的个数是否为奇数 
 - 如 00000 00000 00000 00000 00000 1 表示a的个数为奇数
 - 那么left 到 right 字符串即可表示为 dp[right+1] ^ dp[left]
```
var canMakePaliQueries = function(s, queries) {
  let len = s.length;
  let dp = new Array(len+1);
  dp[0] = 0
  for (let i = 1; i <= len; ++i) {
    dp[i] = dp[i-1] ^ (1 << (s[i-1].codePointAt() - 97))
  }
  return queries.map(([left, right, count]) => {
    count *= 2;
    let res = dp[right+1] ^ dp[left]
    while (res) {
      count -= res & 1
      res >>= 1
    }
    return count >= -1;
  })
};
```
