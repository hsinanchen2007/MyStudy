### 解题思路
先遍历数组找到board[i][j] == 'R'
然后该位置的四个方向找符合条件的p

### 代码

```javascript
/**
 * @param {character[][]} board
 * @return {number}
 */
var numRookCaptures = function(board) {
    //R 捕获 p
    for(let i = 0 ; i <board.length ;i++){
        for(let j=0;j<board[0].length;j++){
              if(board[i][j] == 'R'){
            let cnt=0;
            let delta=1;
            let up=down=left=right=true;
            while(i+delta < 8 || i-delta >= 0 ){
                if(i+delta < 8  &&down){
                    if(board[i+delta][j] === 'p' ){
                        cnt++;
                        down=false;
                    }else if(board[i+delta][j] === 'B' ){
                        down=false;
                    }
                }
                if(i-delta >=0  &&up){
                    if(board[i-delta][j] === 'p' ){
                        cnt++;
                        up=false;
                    }else if(board[i-delta][j] === 'B' ){
                        up=false;
                    }
                }
                delta++;

            }
            delta=1;
            while(j+delta < 8 || j-delta >= 0 ){
                if(j+delta < 8  &&right){
                    if(board[i][j+delta] === 'p' ){
                        cnt++;
                        right=false;
                    }else if(board[i][j+delta] === 'B' ){
                        right=false;
                    }
                }
                if(j-delta >=0  && left){
                    if(board[i][j-delta] === 'p' ){
                        cnt++;
                        left=false;
                    }else if(board[i][j-delta] === 'B' ){
                        left=false;
                    }
                }

                delta++;

            }

            return cnt;


        }

        }
      
    }

};
```