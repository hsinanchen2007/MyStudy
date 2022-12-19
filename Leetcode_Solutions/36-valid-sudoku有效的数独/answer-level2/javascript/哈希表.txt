### 解题思路
![image.png](https://pic.leetcode-cn.com/c22dc004931bf484404000537204698855d8df0548538bf95edaa54bdca62b7a-image.png)

用Map，key = 当前的值，value = 一个二维数组，放已检索到的相同值的坐标，比如例图的5，就是[[0,0],[1,5]..]。逐行逐个检查，若在Map中有，检查坐标
1. 是否同一行
2. 是否同一列
3. 是否同一个九宫格

第3点用 x - x % 3来判断，比如[0,4]和[1,3]在同一个九宫格中，则:
0 - 0 % 3 = 1 - 1 % 3 = 0, 
4 - 4 % 3 = 3 - 3 % 3 = 3

over~
### 代码

```javascript
/**
 * @param {character[][]} board
 * @return {boolean}
 */
var isValidSudoku = function (board) {
    let valAndCoord = new Map(), // key: value number, val: coordinate[[i1,j1],[i2,j2]]
        coordArr = [];

    for (let i = 0; i < 9; i++) {
        for (let j = 0; j < 9; j++) {
            if (board[i][j] === ".") continue;
            const element = parseInt(board[i][j], 10);

            if (valAndCoord.has(element)) {
                coordArr = valAndCoord.get(element);
                for (let k = 0; k < coordArr.length; k++) {
                    const existedCoord = coordArr[k];
                    let isSameRow = (i - i % 3) === (existedCoord[0] - existedCoord[0] % 3),
                        isSameCol = (j - j % 3) === (existedCoord[1] - existedCoord[1] % 3);

                    if (existedCoord[0] === i || existedCoord[1] === j || (isSameRow && isSameCol)) {
                        return false;
                    }
                }
                coordArr.push([i, j]);
                valAndCoord.set(element, coordArr);
            } else {
                coordArr = [];
                coordArr.push([i, j]);
                valAndCoord.set(element, coordArr);
            }
        }
    }
    return true;
};
```