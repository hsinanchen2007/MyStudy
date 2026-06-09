```
var simplifyPath = function (path) {
  path = path.split('/')
  let map = path.reduce((ary, it) => {
    if (it == '' || it == '.' || it == '..') {
      if (ary.length > 0 && it == '..') {
        ary.pop()
      }
    } else {
      ary.push(it)
    }
    return ary
  }, [])
  if (map.length == 0) return '/'
  return map.reduce((res, it) => {
    return res + '/' + it
  }, '')
};
```

