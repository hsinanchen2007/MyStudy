### 解题思路
初始化坐标，根据指示做相应的加减操作，若最后坐标和初始坐标一致，则说明回到原点

### 代码

```javascript
/**
 * @param {string} moves
 * @return {boolean}
 */
var judgeCircle = function(moves) {
    let x = 0;
    let y = 0;
    for(let i =0; i<moves.length; i++){
        switch (moves[i]){
            case 'U':
                y++
                break
            case 'D':
                y--
                break
            case 'R':
                x++            
                break
            case 'L':
                x--
                break
        }
    }
    return x === 0 && y ===0
};
```