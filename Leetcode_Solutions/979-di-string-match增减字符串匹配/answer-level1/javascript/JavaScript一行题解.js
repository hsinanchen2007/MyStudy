```
var diStringMatch = function(S) {let a = 0,b = S.length;return (S+S[S.length - 1]).split('').map((x) => x=='I'?a++:b--)}
```