跟[443.压缩字符串](https://leetcode-cn.com/problems/string-compression/)题很像

```javascript []
var compressString = function(S) {
  let count = 1 //统计字母数量
  let res = '' //结果
  for (let i = 1; i <= S.length; i++) {
    if (S[i] === S[i - 1]) {//字符相等
      count++//计数+1
    } else {
      res = res + S[i - 1] + count//加入结果
      count = 1//初始化计数
    }
  }
  return res.length < S.length ? res : S
}
```

