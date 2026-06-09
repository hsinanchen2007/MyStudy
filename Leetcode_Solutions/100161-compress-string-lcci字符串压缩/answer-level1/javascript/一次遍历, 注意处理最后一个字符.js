```
var compressString = function(S) {
  if (S.length === 0) {
    return S
  } else {
    let res = ''
    let curStr = S[0]
    let curCount = 1
    for (let i = 1; i < S.length; ++i) {
      if (S[i] === curStr) {
        ++curCount
      } else {
        res += curStr + curCount
        curStr = S[i]
        curCount = 1
      }
    }
    res += curStr + curCount
    return res.length < S.length ? res : S
  }
};
```
