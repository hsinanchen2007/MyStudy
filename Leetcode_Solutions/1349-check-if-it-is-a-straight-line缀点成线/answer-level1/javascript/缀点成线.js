### 解题思路

选取coordinates[0]、coordinates[i]、coordinates[i+1] 是否在同一条线上

### 代码

```javascript
var checkStraightLine = function(coordinates) {
    for (let i = 1; i < coordinates.length-1; i++) {
        let y1 = coordinates[i][1] - coordinates[0][1]
        let x1 = coordinates[i][0] - coordinates[0][0]
        let y2 = coordinates[i+1][1] - coordinates[i][1]
        let x2 = coordinates[i+1][0] - coordinates[i][0]
        if (y1*x2 !== x1*y2) {
            return false
        }
    }
    return true
};
```