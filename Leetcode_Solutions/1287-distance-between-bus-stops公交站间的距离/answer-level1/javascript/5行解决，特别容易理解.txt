1.总的距离是total；
2.两站之间的距离为between；
3.因为车是双向的，且是个环；
因此，最短距离dist = min(between, total-between)；

```
var distanceBetweenBusStops = function (distance, start, destination) {
  if (start > destination) return distanceBetweenBusStops(distance, destination, start);

  const distTotal = distance.reduce((s, n) => s + n);
  const distBetween = distance.slice(start, destination).reduce((s, n) => s + n, 0);
  return Math.min(distBetween, distTotal - distBetween);
};
```
