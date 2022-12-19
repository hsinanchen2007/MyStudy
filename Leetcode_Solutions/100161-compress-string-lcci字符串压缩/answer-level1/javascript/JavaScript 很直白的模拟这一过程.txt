> 感觉这应该不需要解释了吧，直接看代码吧。
```js
var compressString = function (S) {
  if (S.length === 0) return S;
  let _s = ""
  let first = S[0]
  let temp = 1
  for (let i = 1; i < S.length; i++) {
    if (S[i] != first) {
      _s = `${_s}${first}${temp}`
      first = S[i]
      temp = 1
    } else {
      temp++
    }
  }
  _s = `${_s}${first}${temp}`
  if (S.length > _s.length) {
    return _s
  } else {
    return S
  }
};
```