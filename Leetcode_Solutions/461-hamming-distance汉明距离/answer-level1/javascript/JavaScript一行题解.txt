```
const hammingDistance = (x, y) => (x ^ y).toString(2).split('').filter(a => a === '1').length
```