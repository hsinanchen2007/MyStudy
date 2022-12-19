```
var selfDividingNumbers = function (left, right) {
  let result = []
  for (let i = left; i <= right; i++) {
    let numberArr = i.toString().split('').map(_ => +_)
    if (!numberArr.includes(0) && numberArr.every(num => i % num === 0)) {
      result.push(i)
    }
  }
  return result
};
```
