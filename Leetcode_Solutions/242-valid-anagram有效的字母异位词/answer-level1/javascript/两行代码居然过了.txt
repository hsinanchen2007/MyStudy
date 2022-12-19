
```
var isAnagram = function(s, t) {
  const sort = (str) => str.split('').sort((a, b) => a.charCodeAt() - b.charCodeAt()).join('')
  return sort(s) === sort(t)
};
```