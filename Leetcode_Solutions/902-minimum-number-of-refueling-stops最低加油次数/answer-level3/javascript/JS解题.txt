### 解题思路
根据当前油量尽可能远的跑，直到跑不到下一个加油站的时候，把路过的加油站的max(stations[i][1])加到当前油量，如此往复继续跑。

js不自带优先队列和堆，那就多排几次序吧...

### 代码

```javascript
var minRefuelStops = function (target, startFuel, stations) {
    if (startFuel >= target) return 0
    let ans = 0, vis = [], fuel = startFuel
    for (let i = 0; i < stations.length; i++) {
        if (fuel >= stations[i][0]) {
            vis.push(stations[i][1])
            continue
        }

        vis.sort((a,b) => a > b ? 1 : -1)
        while (fuel < stations[i][0]) {
            if (vis.length > 0) {
                fuel += vis.pop()
                ans++
                if(fuel >= target) return ans
            }
            else return -1
        }
        vis.push(stations[i][1])
    }
    vis.sort((a,b) => a > b ? 1 : -1)
    while (fuel < target) {
        if (vis.length > 0) {
            fuel += vis.pop()
            ans++
        }
        else return -1
    }
    return ans
};
```