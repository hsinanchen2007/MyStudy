### 解题思路
递归和回溯。每一行只可能存在一个皇后，所以递归地在每一行的每个位置上向后推进，递归下去的条件是水平方向和垂直方向，以及两条对角线上都还未被放置皇后。递归的终止条件就是跑到了最后一行的下一行。此时也是收集到一个满足条件的皇后的时候，再回溯进行下一个收集。

重点在于怎么确定两个点在某一条对角线上。把对角线划分成两种，右倾的对角线和左倾的对角线，右倾的对角线x，y坐标之和相等即为同一条对角线，左倾的对角线x，y轴之差相等即为同一条对角线。

有人可能觉得这样递归是不是时间复杂度会很大。其实没那么大，这里面还有剪枝，不符合条件的分支就直接略过了。


### 代码

```javascript
/**
 * @param {number} n
 * @return {string[][]}
 */
var solveNQueens = function(n) {
    let res = [];
    // 垂直方向的占用情况
    var vertical = {};
    // 水平方向的占用情况
    var horitonal = {};
    // 右倾斜对角线的占用情况
    var diagonalRight = {};
    // 左倾斜对角线的占用情况
    var diagonalLeft = {};

    putQueen(n,0,[])
    return res

    /**
     * 尝试在n皇后的问题中，摆放第index行的皇后的位置
     */
    function putQueen(n,index,arr){
        if(n == index) {
            res.push(genaraterQueen(n,[...arr]))
        }
        for(var i=0;i<n;i++) {
            if(!vertical[i] && !horitonal[index] &&
            !diagonalRight[i+index] && !diagonalLeft[i-index]){
                arr.push(i);
                vertical[i] = true;
                horitonal[index] = true;
                diagonalRight[i+index] = true;
                diagonalLeft[i-index] = true;
                putQueen(n,index+1, arr);
                arr.pop();
                vertical[i] = false;
                horitonal[index] = false;
                diagonalRight[i+index] = false;
                diagonalLeft[i-index] = false;
            }
        }
    }

    function genaraterQueen(n,arr) {
        var result = [];
        for(var i=0;i<n;i++) {
            result.push(new Array(n).fill('.'));
        }

        for(var p=0;p<n;p++) {
            result[p][arr[p]] = "Q"
            result[p] = result[p].join("")
        }
        return result
    }



};
```