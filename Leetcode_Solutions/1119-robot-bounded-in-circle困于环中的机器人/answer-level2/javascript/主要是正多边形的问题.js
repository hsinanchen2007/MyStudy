1.如果一轮之后回到（0， 0），那一定循环
2.如果一轮之后方向向上，那么会一直往上走，不会循环
3.如果一轮之后方向是其它方向，那么要么构成正多边形（远点是正多边形的一个顶点），要么在一条线段上循环往复。就这样
```
/**
 * @param {string} instructions
 * @return {boolean}
 */
var isRobotBounded = function(instructions) {
    // 0、1、2、3分别代表上、右、下、左
    let dir = 0
    let x = 0
    let y = 0
    instructions.split('').forEach(v => {
        switch(dir) {
            // 上
            case 0: {
                if(v === 'G') {
                    y -= 1
                } else if(v === 'L') {
                    dir = 3
                } else if(v === 'R') dir = 1
            }
            break
            // 右
            case 1: {
                if(v === 'G') {
                    x += 1
                } else if(v === 'L') {
                    dir = 0
                } else if(v === 'R') dir = 2
            }
            break
            // 下
            case 2: {
                if(v === 'G') {
                    y += 1
                } else if(v === 'L') {
                    dir = 1
                } else if(v === 'R') dir = 3
            }
            break
            // 左
            case 3: {
                if(v === 'G') {
                    x -= 1
                } else if(v === 'L') {
                    dir = 2
                } else if(v === 'R') dir = 0
            }
            break
        }
    })
    if((x === 0) && (y === 0)) return true
    if(dir !== 0) return true
    return false 
};
```
