### 解题思路
上下左右分四步走。
### 代码

```javascript
/**
 * @param {number[][]} matrix
 * @return {number[]}
 */
var spiralOrder = function(matrix) {
    if(matrix.length <= 0 || matrix[0].length <= 0){
        return []
    }
    let xlen = matrix.length;
    let ylen = matrix[0].length;
    let result = [];
    let all = xlen * ylen;
    function goRight(now){
        for(let j = now; j <= ylen - 1 - now; j++){
            if(result.length == all){
                return;
            }
            result.push(matrix[now][j]);
        }
    }
    function goDown(now){
        for(let j = now+1; j < xlen - 1 - now; j++){
            if(result.length == all){
                return;
            }
            result.push(matrix[j][ylen-1-now])
        }
    }
    function goLeft(now){
        for(let j = ylen-1-now; j > now; j--){
            if(result.length == all){
                return;
            }
            result.push(matrix[xlen - 1 - now][j])
        }
    }
    function goUp(now){
        for(let j = xlen - 1 - now; j > now; j--){
            if(result.length == all){
                return;
            }
            result.push(matrix[j][now])
        }
    }
    let now = 0;
    while(result.length < all){
        goRight(now);
        goDown(now);
        goLeft(now);
        goUp(now);
        now++;
    }
    return result;
};
```