```js
var distanceBetweenBusStops = function(distance, start, destination) {
    if (start > destination) {
        [start, destination] = [destination, start]
    }

    // 环形总和
    let total = 0;
    distance.forEach((i) => total += i)

    // 顺时针的和
    let sum = 0
    for (let i = start; i < destination; i++) {
        sum += distance[i]
    }
    
    return Math.min(sum, total-sum)
};
```
