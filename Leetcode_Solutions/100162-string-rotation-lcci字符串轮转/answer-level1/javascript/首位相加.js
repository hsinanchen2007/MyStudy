```javascript
var isFlipedString = function(s1, s2) {
  if(s1.length != s2.length) return false
  let ss = s1 + s1
  if(ss.includes(s2)) return true
  else return false 
};
```
