```
/**
 * @param {number[][]} points
 * @return {number}
 */
var minAreaFreeRect = function(points) {
    const n = points.length
    const map = new Map()
    for(let i = 0;i < n;i++) {
        for(let j = i + 1;j < n;j++) {
            const center = [points[i][0] + points[j][0], points[i][1] + points[j][1]] + ''
            let r = (points[i][0] - points[j][0]) ** 2
            r += (points[i][1] - points[j][1]) ** 2
            if(!map.has(r)) {
                map.set(r, new Map())
            }
            if(!map.get(r).has(center)) {
                map.get(r).set(center, [])
            }
            map.get(r).get(center).push([ points[i], points[j] ])
        }
    }
    let ans = Infinity
    for(let r of map) {
        for(let entry of r[1]) {
            const list = entry[1]
            if(list.length < 2) continue
            for(let i = 0;i < list.length;i++) {
                for(let j = i + 1;j < list.length;j++) {
                    const dot1 = list[i][0]
                    const dot2 = list[j][0]
                    const dot3 = list[j][1]
                    let area = (dot1[0] - dot2[0]) ** 2 + (dot1[1] - dot2[1]) ** 2
                    area *= ((dot1[0] - dot3[0]) ** 2 + (dot1[1] - dot3[1]) ** 2)
                    ans = Math.min(Math.sqrt(area), ans)
                }
            }
        }
    }
    return ans === Infinity ? 0 : ans
};
```
