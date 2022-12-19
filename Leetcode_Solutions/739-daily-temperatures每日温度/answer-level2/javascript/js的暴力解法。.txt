基本思路就是拿当前的项对比后面所有项，遇到比自己大的就停止，记录当前下标，如果一直没找到，记录0.

``` javascript
var dailyTemperatures = function(T) {
    let nextDays = []
    T.forEach((item, index) => {
      let nextDay = 0;
      for(let x = index + 1; x < T.length; x++) {
        if (T[x] > item) {
          nextDay = x - index;
          break
        }
      }
     nextDays.push(nextDay)
    })

    return nextDays
};
```
