### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string} moves
 * @return {boolean}
 */
var judgeCircle = function(moves) {
    if(!moves.length)return true;
    const vmap = new Map();//垂直移动
    vmap.set('U', 1);
    vmap.set('D', -1);
    const pmap = new Map();//水平移动
    pmap.set('L', 1);
    pmap.set('R', -1);

    const movesArr=moves.split('');
    const vmoves = movesArr.filter(m=>m=='U' || m == 'D');
    const pmoves = movesArr.filter(m=>m=='L' || m == 'R');
    //计算各个方向移动的矢量相加结果
    const cauculateCoord = (moves, map) => moves.reduce((acc, m)=>{acc+=map.get(m); return acc;}, 0);
    //如果垂直和水平移动的矢量相加结果是0即表示在起点
    return !cauculateCoord(vmoves, vmap) && !cauculateCoord(pmoves, pmap);
};
```