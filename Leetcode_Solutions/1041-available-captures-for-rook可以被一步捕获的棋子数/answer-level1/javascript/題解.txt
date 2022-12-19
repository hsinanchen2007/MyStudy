### 解题思路
找到R然後依照x軸y軸用forloop找p

### 代码

```javascript
/**
 * @param {character[][]} board
 * @return {number}
 */
var numRookCaptures = function(board) {
    let res=0;
    for(let i=0;i<board.length;i++){
            let rookY=board[i].indexOf('R');
            if(rookY!==-1){
                let rookX=i;
                for(let i=rookY+1;i<8;i++){
                    if(board[rookX][i]!="."){
                        if(board[rookX][i]=="p"){
                            res++;
                        }
                        break;
                    }
                }
                for(let i=rookY-1;i>0;i--){
                    if(board[rookX][i]!="."){
                        if(board[rookX][i]=="p"){
                            res++;
                        } 
                        break;
                    }
                }
                for(let i=rookX+1;i<8;i++){
                    if(board[i][rookY]!="."){
                        if(board[i][rookY]=="p"){
                            res++;
                        }
                        break;
                    }
                }
                for(let i=rookX-1;i>0;i--){
                    if(board[i][rookY]!="."){
                        if(board[i][rookY]=="p"){
                            res++;
                        } 
                        break;
                    }
                }
                break;
            }
    }
   
    return res;
};
```