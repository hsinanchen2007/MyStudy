### 解题思路
@Parsee仿大神写法，不得不说位运算牛逼！
### 代码

```javascript
/**
 * @param {character[][]} board
 * @return {boolean}
 */
var isValidSudoku = function(board) {
    let res = []
    for (let i = 0; i < 9; i++) {
        for (let j = 0; j < 9; j++) {
            let val = board[i][j]-1
            // 用字符串和数字做减法，判断该字符串是否是纯数字字符串
            // 同时给res分配键值0到8，长度为9的数组
            if (val>=0 && val<=8) {
                // bitMap 用，分别给行、列、子数独分配9位的独立空间，
                // 1 <<j  代表列 
                // 1 << i+9 代表行 
                // 1 <<  Math.floor(i/3)*3+Math.floor(j/3) + 18 代表子数独 
                //  由行、列、子数独所在的位置（即1的位置）记录该值的坐标
                let cur = 1 << j | 1 << i+9  | 1 <<  Math.floor(i/3)*3+Math.floor(j/3) + 18
                let old = res[val]
                if ((old & cur) == 0) {
                    //该数添加新的坐标
                    res[val] = old | cur
                } else {
                    //该数重复出现
                    return false

                }
            }
             
        }
    }
   
    return true
 };
```