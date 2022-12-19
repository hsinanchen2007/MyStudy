### 解题思路
遍历数组，先找到车的位置，并完成车所在行的遍历，记录车的左右黑旗数量，然后根据记录的车的位置，遍历车上下的黑旗数量

### 代码

```javascript
/**
 * @param {character[][]} board
 * @return {number}
 */
var numRookCaptures = function(board) {
    var length = board.length;
    var row = -1;
    var col = -1;
    var p = '';   // 黑族
    var result = 0;
    for(var i = 0; i < length ; i++){
        var temp = board [i];
        var hasR = false;
        p ='';
        for(var j = 0; j < temp.length ; j++){
            
            if(hasR){
                if(temp[j]== 'p'){
                    result = result +1;
                    hasR = false;
                    continue;
                }
                if(temp[j] == 'B'){
                    hasR = false;
                   continue;
                }
            }else{
                if(temp[j]== 'p'){
                    p= 'p' ;
                }
                if(temp[j] == 'B'){
                    p = '';
                }
                if(temp[j] == 'R'){
                    row= i;
                    col = j;
                    hasR = true;
                    if(p == 'p'){
                        result = result +1;
                    }
                    p = '';
                }
            }
            if(hasR && j == temp.length -1){
                break;
            }
        }
    }
    var top = row, bottom = row;
    while(top >= 0){
        if(board[top][col] === 'p'){
            result = result +1;
            break;
        }else if(board[top][col]  === 'B'){
            break;
        }
        top--;
    }
    while(bottom < length){
        if(board[bottom][col] === 'p'){
            result = result +1;
            break;
        }else if(board[bottom][col] === 'B'){
            break;
        }
        bottom++;
    }

    return result;
};
```