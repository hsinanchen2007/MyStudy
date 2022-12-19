### 解题思路

![image.png](https://pic.leetcode-cn.com/97a8bf95ce9096ceeb6bfd836a975baf9a79ba45386b290cac91ca8ac1383f36-image.png)

- 新建一个二维数组，将 moves 的地方填充进去
- 通过if判断 行 列 对角线 得知

### 代码

```javascript
/**
 * @param {number[][]} moves
 * @return {string}
 */
var tictactoe = function(moves) {
    let A = []
    let B = []
    for(let i = 0; i < 3; i++){
    if(!Array.isArray(A[i] && B[i])){
     A[i] = new Array(3).fill(0)
     B[i] = new Array(3).fill(0)
    }
    }
    for(let j = 0; j < moves.length ; j++){
        if(j % 2==0){
            A[moves[j][0]][moves[j][1]] = 1
        }else{
            B[moves[j][0]][moves[j][1]] = 2
        }
    }
    
    for(let i = 0; i < 3; i++){
        if(A[i][0] + A[i][1] + A[i][2] == 3) return "A";
        if(A[0][i] + A[1][i] + A[2][i] == 3) return "A";
        if((A[0][0] + A[1][1] + A[2][2] == 3) || A[2][0] + A[1][1] + A[0][2] == 3) return "A";
        if(B[i][0] + B[i][1] + B[i][2] == 6) return "B";
        if(B[0][i] + B[1][i] + B[2][i] == 6) return "B";
        if((B[0][0] + B[1][1] + B[2][2] == 6) || B[2][0] + B[1][1] + B[0][2] == 6) return "B";
    }
    if(moves.length == 9) return "Draw"
    return "Pending"
    
};
```