### 解题思路
![微信截图_20200408104750.png](https://pic.leetcode-cn.com/f08263679d2faf5c9f46105b05fab84003f31d1c90c475610217e8a5b9edeea3-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20200408104750.png)

一开始我是写成把 行，列，九宫格三种二维数组都生成，再去判断改二位数组对应的行是否存在重复。这样多用了几个循环，觉得挺简单的就写出来了。
晚上睡觉的时候突然脑子一热，为什么不再生成数组的时候顺带做下判断不是更快，就劈里啪啦的改写的，更简洁一些。
这种就是数独的规则，有玩过的人理解起来就很简单。

### 代码

```javascript
/**
 * @param {character[][]} board
 * @return {boolean}
 */
var isValidSudoku = function(board) {
    let rows=[],    // 行
        columns=[], // 列
        grids=[];   // 9宫格
    // 生成二维空数组 [9][9]
    for(let i=0;i<9;i++){
        rows[i]=[];
        columns[i]=[];
        grids[i]=[];
    }
    for(let i=0;i<9;i++){
        // 赋值 并判断
        for(let j=0;j<9;j++){
            // 九宫格对应的下标
            let gridsRow=parseInt(i/3) * 3 + parseInt(j/3); 
            // 判断行和九宫格是否存在相同元素
            if(board[i][j]!='.'){
                if(rows[i].indexOf(board[i][j])>=0 || grids[gridsRow].indexOf(board[i][j])>=0){
                    return false;
                }
                rows[i].push(board[i][j]);  // 行
                grids[gridsRow].push(board[i][j]);
            }
            // 判断列是否存在相同元素
            if(board[j][i]!='.'){
                if(columns[i].indexOf(board[j][i])>=0){
                    return false;
                }
                columns[i].push(board[j][i]);
            }
        }
    }
    return true
};
```