// ### 解题思路
// ![100leetcode.png](https://pic.leetcode-cn.com/9abfb92e3edb1b7b291955a2da6481bb53f4919e82f6413cd81a64ba21400910-100leetcode.png)

// 第一次暴力解超时，我思考了下，因为障碍物数组`reservedSeats`的遍历是不可避免的，所以设置了`七种状态`，用于`剪枝`
// 但是，做完后发现还是`超时`。
// 仔细思考了下🤔，题中隐藏条件是 `reservedSeats.length = min(n * 10, 10 ^ 4)`
// 这说明 障碍物`至多` 只可以分布在 `10的4次方` 行中。
// 由于 `n` 的量级 是  `10 的 9次方` 
// 故

// 当`n` 大于 `10 的 4 次方` 时，不存在障碍物的行数都是 可以坐 左 和 右（即 `结果 +2`）
// `res += (n - Object.keys(flag).length) * 2`

// 整体思想分两步

// - 遍历`障碍物`数组，`状态降级`，收集 `flag` 对象
// - 遍历 `n`  求解（10的4次方是临界值，遍历 `flag key`，剩余`乘以2`）

// #### 状态降级

// 每一行总共可能的出现的状态是

// 1. 一个四连都没有 `none`，计算时记为 0
// 2. 左和右都可以四连 `lr`， 计算时 记为 2
// 3. 左中右 各自坐四连 `left、mid、right` 计算时 为 1
// 4. 左中 和 右中 两种状态 `lm、rm`  因为是互斥的（2-6 可以坐，但是只能出现一个四连）所以计算时为 1

// 遍历障碍物数组

// 默认每行状态都能取到 `lr`，根据障碍物坐标进行 `状态降级`

// 当 `reservedSeats[i][1] == 2 || reservedSeats[i][1] == 3` 时，说明 左侧四连肯定不能坐
// 如果本行状态为 `lr`，降级为 `rm`
// 如果本行状态为 `left` 降级为 `none`
// 如果本行状态为 `lm` 降级为 `mid`

// 其余看代码吧～
// ### 代码

// ```javascript
/**
 * @param {number} n
 * @param {number[][]} reservedSeats
 * @return {number}
 */
// 七种状态
// status = ['left','right', 'mid', 'lr', 'none', 'rm', 'lm']
let res
let vMax
let flag
var maxNumberOfFamilies = function(n, reservedSeats) {
    vMax = n
    res = 0
    flag = {}
    
    for(let i in reservedSeats){
        flag[reservedSeats[i][0]] = flag[reservedSeats[i][0]] || 'lr'
        if(flag[reservedSeats[i][0]] == 'none') continue
        // 降级
        
        if(reservedSeats[i][1] == 2 || reservedSeats[i][1] == 3){
            if(flag[reservedSeats[i][0]] == 'left') flag[reservedSeats[i][0]] = 'none'
            if(flag[reservedSeats[i][0]] == 'lr') flag[reservedSeats[i][0]] = 'rm'
            if(flag[reservedSeats[i][0]] == 'lm') flag[reservedSeats[i][0]] = 'mid'
        }else if(reservedSeats[i][1] == 4 || reservedSeats[i][1] == 5){
            if(flag[reservedSeats[i][0]] == 'lm' || flag[reservedSeats[i][0]] == 'left' || flag[reservedSeats[i][0]] == 'mid') flag[reservedSeats[i][0]] = 'none'
            if(flag[reservedSeats[i][0]] == 'lr' || flag[reservedSeats[i][0]] == 'rm') flag[reservedSeats[i][0]] = 'right'
        }else if(reservedSeats[i][1] == 6 || reservedSeats[i][1] == 7){
            if(flag[reservedSeats[i][0]] == 'rm' || flag[reservedSeats[i][0]] == 'right' || flag[reservedSeats[i][0]] == 'mid') flag[reservedSeats[i][0]] = 'none'
            if(flag[reservedSeats[i][0]] == 'lr' || flag[reservedSeats[i][0]] == 'lm') flag[reservedSeats[i][0]] = 'left'
        }else if(reservedSeats[i][1] == 8 || reservedSeats[i][1] == 9){
            if(flag[reservedSeats[i][0]] == 'right') flag[reservedSeats[i][0]] = 'none'
            if(flag[reservedSeats[i][0]] == 'lr') flag[reservedSeats[i][0]] = 'lm'
            if(flag[reservedSeats[i][0]] == 'rm') flag[reservedSeats[i][0]] = 'mid'
        }
    }

    // 超过十的四次方,遍历reservedSeats，剩下 res += (n - reservedSeats.length) * 2
    if(n * 10 > Math.pow(10,4)){
        for(let i of Object.keys(flag)){
            if(flag[i] == 'lr'){
                res += 2
                continue
            }
            if(flag[i] == 'none') continue
            res++
        }
        res += (n - Object.keys(flag).length) * 2
        return res
    }
    for(let i = 1; i< n+1; i++){
        if(!flag[i] || flag[i] == 'lr'){
            res += 2
            continue
        }
        if(flag[i] == 'none') continue
        res++
    }
    return res
};
// ```