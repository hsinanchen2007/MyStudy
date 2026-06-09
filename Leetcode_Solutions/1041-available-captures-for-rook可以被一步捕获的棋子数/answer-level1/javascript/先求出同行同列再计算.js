### 解题思路
先求出同行和同列旗子`sameX`和`sameY`，再缩小范围求解

### 代码

```javascript
/**
 * @param {character[][]} board
 * @return {number}
 */
var numRookCaptures = function(board) {
    const x = board.findIndex(key=>key.includes('R'))
    const y = board[x].findIndex(key=>key==='R')

    const sameX = board[x]
    const sameY = board.reduce((arr,item)=>[...arr,item[y]],[])

    let xMin=0,xMax=sameX.length,yMin=0,yMax=sameY.length;

    sameX.forEach((key,index)=>{
        if((key === 'B' || key === 'p') && index < x) xMin = index
        if((key === 'B' || key === 'p') && index > x) xMax = xMax < index?xMax:index;
    })
    sameY.forEach((key,index)=>{
        if((key === 'B' || key === 'p') && index < y) yMin = index
        if((key === 'B' || key === 'p') && index > y) yMax = yMax < index?yMax:index;
    })
    return sameX.slice(xMin,xMax + 1).filter(key=>key==='p').length + sameY.slice(yMin,yMax + 1).filter(key=>key==='p').length
};
```