```
/**
 * @param {number[][]} matrix
 * @return {number}
 * 只有某两行对应元素全部相同或相反，变换任意列数的列后这两行才能
 * 同时各自行内元素全部相同，否则不论变换哪几列、这两行一定有一行无法做到
 * 行内元素全部相同
 * 题目要求变换任意列数的列后行内元素相同的列的最大数量，
 * 就是要求原矩阵中按位全部相同或全部相反的行的最大数量。
 */
var maxEqualRowsAfterFlips = function(matrix) {
    let res = 0
    let map = new Map()
    let p = 0
    let temp = ''
    for(let r of matrix) {
        p = 1 ^ r[0]
        for(let i = 0;i < r.length;i++)  r[i] = r[i] ^ p
        temp = r.join('')
        if(map.has(temp)) {
            map.set(temp, map.get(temp) + 1)
        } else map.set(temp, 1)
        res = Math.max(res, map.get(temp))
    }
    return res
}; 
```
代码块
```
```
