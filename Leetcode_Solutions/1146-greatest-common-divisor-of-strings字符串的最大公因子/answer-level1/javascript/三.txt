```
var gcdOfStrings = function(str1, str2) {
  let n1 = str1.length, n2 = str2.length
  if(n1 === n2) {
    if(str1 === str2) return str1
    else return ''
  }
  if(n1 < n2) {
    let tmp = str2.split(str1).filter((val) => val !== '')
    if(tmp.length === 0) return str1
    else if(tmp.length > 1 || tmp[0] === str2) return ''
    else return gcdOfStrings(tmp[0], str1)
  }

  if(n1 > n2) {
    let tmp = str1.split(str2).filter((val) => val !== '')
    if(tmp.length === 0) return str2
    else if(tmp.length > 1 || tmp[0] === str1) return ''
    else return gcdOfStrings(tmp[0], str2)
  }
};

```
