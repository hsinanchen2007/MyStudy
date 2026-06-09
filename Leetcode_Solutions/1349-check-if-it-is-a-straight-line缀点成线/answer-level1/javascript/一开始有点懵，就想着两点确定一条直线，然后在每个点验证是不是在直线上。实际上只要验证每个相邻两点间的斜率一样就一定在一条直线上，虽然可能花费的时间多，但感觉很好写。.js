### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[][]} coordinates
 * @return {boolean}
 */
var checkStraightLine = function(c) {
    // 遍历两点间若斜率不一样就不是一条直线
    var k = (c[1][1] - c[0][1]) / (c[1][0] - c[0][0])
    for(let i = 0; i< c.length - 1; i++) {
        kk = (c[i+1][1] - c[i][1]) / (c[i+1][0] - c[i][0])
        if(k !== kk) {
            return false
        }
    }
    return true
};

```