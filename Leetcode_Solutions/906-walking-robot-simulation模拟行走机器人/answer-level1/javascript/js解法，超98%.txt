```
/**
 * @param {number[]} commands
 * @param {number[][]} obstacles
 * @return {number}
 */
var robotSim = function(commands, obstacles) {
    let obstaclesSet = new Set();
    for (let i = 0; i < obstacles.length; i++) {
        let str = obstacles[i][0] + "," + obstacles[i][1];
        obstaclesSet.add(str);
    }
    let dx = [0, 1, 0, -1];
    let dy = [1, 0, -1, 0];
    let x = 0;
    let y = 0;    //  从原点开始出发，用x,y来记录当前位置
    let di = 0;   // 标志当前应该往哪个方向走，0表示往北，1表示往右，2表示往下，3表示往左，关键一点
    let ans = 0;
    for (let j = 0; j < commands.length; j++) {
        if (commands[j] === -2) {    // 向左转90度
            di = (di + 3) % 4;
        } else if (commands[j] === -1) {    // 向右转90度
            di = (di + 1) % 4;
        } else {
            for (let k = 0; k < commands[j]; k++) {
                let nx = x + dx[di];
                let ny = y + dy[di];
                let code = nx + "," + ny;
                if (!obstaclesSet.has(code)) {
                    x = nx;
                    y = ny;
                    ans = Math.max(ans, x*x + y*y);
                } else {
                    break;        // 遇到障碍，跳出本次命令，接着走下一步
                }
            }
        }
    }
    return ans;
};
```
