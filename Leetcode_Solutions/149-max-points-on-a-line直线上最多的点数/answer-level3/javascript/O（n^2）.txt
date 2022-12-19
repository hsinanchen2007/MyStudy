这道题目的关键是, 假设a0,a1,a2,a3.......an-2,an-1中，要知道a1,a2,a3三点是否在同一条直线上， 我只要确定a1和a2的斜率k1,a1,a3的斜率k2有k1 === k2即可， 不用再去算a2,a3的斜率k3是否与k1、k2相同。通过第零趟遍历，我能算出与(a0,a1),(a0, a2), (a0, a3), ....,(a0, an-1)斜率相同的点分别有多少个，
通过第i趟遍历， 我能算出与(ai, ai+1),(ai, ai+2),(ai,ai+3),....(ai, an-1)斜率相同的点有多少.这样通过O(n^2)的遍历，我就把这些点所有可能产生的斜率以及每种斜率有多少点在一条直线上都遍历了
当然重合的点要另外处理

```
/**
 * @param {number[][]} points
 * @return {number}
 */
var maxPoints = function(points) {
    if(points.length < 3) return points.length
    let map = new Map()
    let gradient = 0
    let ans = 0
    let count = undefined
    let same = undefined
    for(let i = 0; i < points.length; i++) {
        const p1 = points[i]
        count = 0
        same = 0
        for(let j = i + 1; j < points.length; j++) {
            const p2 = points[j]
            let dx = p1[0] - p2[0]
            let dy = p1[1] - p2[1]
            const g = gcd(dx, dy)
            if(g !== 0) {
                dx /= g
                dy /= g
            }
            if((dy === 0) && (dx === 0)) {
                same++
            }else {
                if(dx === 0) {
                    gradient = Infinity
                } else {
                    if(dy === 0) dx = 1
                    gradient = `${dx},${dy}`
                }
                let temp = map.get(gradient)
                if(temp === undefined) {
                    temp = 2
                } else temp += 1
                map.set(gradient, temp)
                if(temp > count) count = temp
            }
        }
        if(count === 0) {
            ans = Math.max(ans, same + 1)
        } else{
            ans = Math.max(ans, same + count)
        }
        map = new Map()
    }
return ans
};


function gcd(a, b) {
    if(b === 0) return a
    return gcd(b, a % b)
}
```
