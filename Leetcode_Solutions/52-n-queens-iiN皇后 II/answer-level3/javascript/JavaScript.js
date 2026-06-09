### 解题思路
递归 + 回溯

### 代码

```javascript
/**
 * @param {number} n
 * @return {number}
 */
var totalNQueens = function(n) {
    let res = 0;
    // 垂直方向的占用情况
    var vertical = {};
    // 水平方向的占用情况
    var horitonal = {};
    // 右倾斜对角线的占用情况
    var diagonalRight = {};
    // 左倾斜对角线的占用情况
    var diagonalLeft = {};

    putQueen(n,0)
    return res

    /**
     * 尝试在n皇后的问题中，摆放第index行的皇后的位置
     */
    function putQueen(n,index){
        if(n == index) {
            res++
        }
        for(var i=0;i<n;i++) {
            if(!vertical[i] && !horitonal[index] &&
            !diagonalRight[i+index] && !diagonalLeft[i-index]){
                vertical[i] = true;
                horitonal[index] = true;
                diagonalRight[i+index] = true;
                diagonalLeft[i-index] = true;
                putQueen(n,index+1);
                vertical[i] = false;
                horitonal[index] = false;
                diagonalRight[i+index] = false;
                diagonalLeft[i-index] = false;
            }
        }
    }

};
```