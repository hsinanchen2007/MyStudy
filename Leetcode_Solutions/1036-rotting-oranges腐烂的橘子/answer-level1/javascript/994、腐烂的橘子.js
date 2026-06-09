### 解题思路


### 代码

```javascript
/**
 * @param {number[][]} grid
 * @return {number}
 */
var orangesRotting = function(grid) {
    var queue = [];
    var hashMap = {};
    var iLen = grid.length;//行数
    var jLen = grid[0].length;//列数
    var time=0;
//首先遍历所有的橘子，将所有的腐烂句子存入队列中，并且在之后的腐烂过程中，会实时更新
    for(var j=0;j<jLen;j++) {
        for(var i=0;i<iLen;i++) {
            if(grid[i][j] == 2) {
                var code = i*jLen + j;
                queue.push(code);
                hashMap[code] =0;//记录对应腐烂橘子腐烂的时长
            }
        }
    }
//对队列中的每一个橘子依次移除，判断四个方向上的橘子是否为新鲜橘子，如果是新鲜橘子，就将其变成2（腐烂橘子）
//同时将这个刚变成的腐烂橘子压入腐烂橘子队列中
    const arrI = [0,1,0,-1];
    const arrJ = [-1,0,1,0];
    while(queue.length){
        var code = queue.shift();
        var j = code % jLen;
        var i = Math.floor(code/jLen);
        for(var k=0;k<4;k++) {
            const newI = i + arrI[k];
            const newJ = j + arrJ[k];
            if(newI>=0 && newI<iLen && newJ>=0 && newJ<jLen && grid[newI][newJ] === 1) {
                grid[newI][newJ]=2;
                const newCode = newI * jLen + newJ;
                queue.push(newCode);
                time = hashMap[newCode]=hashMap[code] +1;
            }
        }
    }
//遍历是否还有新鲜橘子，如果有返回-1；
    for(var i=0;i<iLen;i++){
        for(var j=0;j<jLen;j++){
            if(grid[i][j]===1){
                return -1;
            }
        }
    }
//没有新鲜橘子，返回腐烂的时间
    return time;
};
```