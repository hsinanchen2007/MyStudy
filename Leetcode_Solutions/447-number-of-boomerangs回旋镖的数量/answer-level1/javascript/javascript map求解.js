### 解题思路
使用map存储距离信息

### 代码

```javascript
/**
 * @param {number[][]} points
 * @return {number}
 */
var numberOfBoomerangs = function(points) {
    const len = points.length
    if (len < 3) {
        return 0
    }
    let count = 0
    for (let i = 0; i < len; i++) {
        const point1 = points[i]
        // 用一个map存储其它点距离当前点point1有多少种距离可能
        const map = new Map()   
        for (let j = 0; j < len; j++) {
            if (i != j) {
                const point2 = points[j]
                const distance = getDistance(point1, point2)
                if (!map.has(distance)) {
                    map.set(distance, 1)
                } else {
                    map.set(distance, map.get(distance) + 1)
                }
            }
        }
        map.forEach(value => {
            if (value > 1) {
                const num = getArrangementNum(value)
                count += num
            }
        })
    }
    return count
};

// 计算两点之间距离，这里其实没必要开根号
function getDistance (p1, p2) {
    const distance = Math.sqrt(Math.pow(p1[0] - p2[0], 2) + Math.pow(p1[1] - p2[1], 2))
    return distance
}

// 计算排列数
function getArrangementNum (n) {
    return n * (n - 1)
}
```