逐字符比较，时间复杂度O(N)

```javascript
var oneEditAway = function(first, second) {
  let firstp = secondp = 0
  if(first.length - second.length > 1 ||first.length - second.length < -1) return false
  let flag = 0
  while(first.length>firstp || second.length>secondp){
    if(first.charAt(firstp) == second.charAt(secondp)) {firstp++;secondp++}
    else{
      if(++flag > 1) return false
      if(first.charAt(firstp + 1) == second.charAt(secondp)) firstp++
      else if(first.charAt(firstp) == second.charAt(secondp + 1)) secondp++
      else if(first.charAt(firstp + 1) == second.charAt(secondp + 1)) {firstp++;secondp++}
      else return false
    }
  }
  return true
};
```