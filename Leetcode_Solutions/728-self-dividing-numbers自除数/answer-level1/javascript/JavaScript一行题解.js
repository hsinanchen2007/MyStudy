```
var selfDividingNumbers = (l, r) => new Array(r-l+1).fill(0).map((x, i) => l+i).filter(x => [...x.toString()].every(y => x%parseInt(y, 10) == 0))
```