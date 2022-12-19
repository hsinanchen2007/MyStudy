1. 先处理边界状态，比如0行或者1行或者1列的情况
2. 确保矩阵的行和列都有两行以上
3. 设定范围，范围用数组保存（第一个是所在的行，第二个是所在的列），限定左上角为[0,0]，右上角为[0,n]，左下角为[m,0]
4. 如果左上角的所在行比左小角所在行小，开始遍历matrix
5. 如果当前是在左上角所在的行，那么遍历左上角所在的行，直到左上角所在列等于右上角所在列，用一个临时数组存储遍历成功的数，同时用另外一个临时数组存储左小角所在行的数字（反向存储）
6. 左上角所在的行遍历完毕后，继续遍历matrix，直到index等于左下角所在行，分别用临时数组存储每一行数，index分别为左上角的列数和右上角的列数。
7. 最后把四个数组连接起来
8. 重复以上步骤直到不满足循环条件

```javascript
/**
 * @param {number[][]} matrix
 * @return {number[]}
 */
var spiralOrder = function(matrix) {
  const m = matrix.length;
  
  /** 边界状态 */
  if (m === 0) return [];
  if (m === 1) return matrix[0];
  
  const n = matrix[0].length;
  
  if (n === 1) { return matrix.reduce((acce, currV) => {
    return acce.concat(currV);
  }, []) }
  
  let topL = [0,0];
  let topR = [0,n];
  let bottomL = [m,0];
  
  let res = [];
  let tmpStartRow;
  let tmpEndRow;
  let tmpStartCol;
  let tmpEndCol;
  
  const closeIn = () => {
    topL[0] += 1;
    topL[1] += 1;
    topR[0] += 1;
    topR[1] -= 1;
    bottomL[0] -= 1;
    bottomL[1] += 1;
  }
  
  while (topL[0] < bottomL[0] && topL[1] < topR[1]) {
    tmpStartRow = [];
    tmpEndRow = [];
    tmpStartCol = [];
    tmpEndCol = [];
    for (let i = topL[0]; i < bottomL[0]; i++) {
      if (i === topL[0]) {
        const isSingle = bottomL[0] - 1 === i;
        for (let j = topL[1]; j < topR[1]; j++) {
          tmpStartRow.push(matrix[i][j]);
          !isSingle && tmpEndRow.unshift(matrix[bottomL[0] - 1][j]);
        }
        continue;
      }
      if (i === bottomL[0] - 1) {
        break;
      }
      tmpStartCol.push(matrix[i][topR[1] - 1]);
      if (topR[1] - 1 !== topL[1]) {
        tmpEndCol.unshift(matrix[i][topL[1]]);
      }
    }
    res = res.concat(tmpStartRow, tmpStartCol, tmpEndRow, tmpEndCol);
    closeIn();
  }
  
  return res;
};

```