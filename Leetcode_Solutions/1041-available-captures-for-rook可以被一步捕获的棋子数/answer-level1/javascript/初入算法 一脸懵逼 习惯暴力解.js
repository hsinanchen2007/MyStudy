
![image.png](https://pic.leetcode-cn.com/bd4ab542891cd0f86b3cce77adf17bb95730c09ee65396b9880dfeec06ae4cb4-image.png)

- 初入算法 一脸懵逼 习惯暴力解  但结果好像还行
- 解完再去找简单的答案
- 看题十分钟 理解后还是比较简单的


找到车 寻找上下左右符合条件的卒  然后计数 结束循环


```/**
 * @param {character[][]} board
 * @return {number}
 */
var numRookCaptures = function(board) {
    let num = 0
    for(var i = 0; i < 8; i++){
        // 寻找车 没有车跳过
        if(!board[i].includes('R')) continue
        // 确定车的纵向坐标
        let j = board[i].indexOf('R')

        // 车上方寻找卒
        for(let m = i-1; m > 0; m--){
            if(board[m][j] === 'B') break

            if(board[m][j] === 'p') {
                num++
                break
            }
        }
        // 车下方寻找卒
        for(let n = i+1; n <8; n++){
            if(board[n][j] === 'B') break

            if(board[n][j] === 'p') {
                num++
                break
            }
        }
        // 车左方寻找卒
        for(let k = j-1; k >0; k--){
            if(board[i][k] === 'B') break

            if(board[i][k] === 'p') {
                num++
                break
            }
        }
        // 车右方寻找卒
        for(let p = j+1; p < 8; p++){
            if(board[i][p] === 'B') break

            if(board[i][p] === 'p') {
                num++
                break
            }
        }
    }
    return num
};```
