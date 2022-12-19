
/**
 * @param {number[][]} matrix
 * @return {number[]}
 */
var spiralOrder = function(matrix) {
    if(matrix.length === 0) return []
    let limitTop = -1
    let limitRight = matrix[0].length
    let limitBottom = matrix.length
    let limitLeft = -1
    // 0、1、2、3分别代表右、下、左、上
    let dir = 0
    let pos = [0, 0]
    const ans = []
    ans.push(matrix[0][0])
    while((limitBottom - limitTop > 1) || (limitRight - limitLeft) > 1) {
        // 右
        if(dir === 0) {
            if(pos[0] + 1 < limitRight) {
                ans.push(matrix[pos[1]][++pos[0]])
            }else if(pos[1] + 1 < limitBottom){
                dir = 1
                limitTop++
            } else break
            continue
        }
        // 下
        if(dir === 1) {
            if(pos[1] + 1 < limitBottom) {
                ans.push(matrix[++pos[1]][pos[0]])
            }else if(pos[0] - 1 > limitLeft){
                dir = 2
                limitRight--
            } else break
            continue
        }
        // 左
        if(dir === 2) {
            if(pos[0] - 1 > limitLeft) {
                ans.push(matrix[pos[1]][--pos[0]])
            }else if(pos[1] - 1 > limitTop){
                dir = 3
                limitBottom--
            } else break
            continue
        }
        if(dir === 3) {
            if(pos[1] - 1 > limitTop) {
                ans.push(matrix[--pos[1]][pos[0]])
            }else if(pos[0] + 1 < limitRight){
                dir = 0
                limitLeft++
            }else break
        }
    }
    return ans
};
```
