```javascript
const map = new Map()
for (let i = 0; i < 12; i++) {
  for (let j = 0; j < 60; j++) {
    const time = `${i}:${j < 10 ? '0' + j : j}`
    const count = bitCount(i) + bitCount(j)
    const ls = map.get(count)
    if (ls) {
      map.set(count, [...ls, time])
    } else {
      map.set(count, [time])
    }
  }
}

var readBinaryWatch = function(num) {
  return map.get(num) || []
};

function bitCount(n) {
  let result = 0
  while (n) {
    n = n & (n - 1)
    result++
  }
  return result
}
```