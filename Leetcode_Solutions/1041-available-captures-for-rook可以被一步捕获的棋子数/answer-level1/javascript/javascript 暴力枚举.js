/**
 * @param {character[][]} board
 * @return {number}
 */
var numRookCaptures = function(board) {
    var y = 0;
    var x = 0;
    var k = 0;
    for(var i=0;i<board.length;i++){
        if(board[i].includes('R')){
            y = i;
            x = board[i].indexOf('R');
        }
    };
    for(var i=y;i<board.length;i++){
        // 南
        if(board[i][x] === 'p'){
            k+=1;
            console.log('南',k);
            break;
        }
        if(board[i][x] === 'B'){
            break;
        }
    }
    for(var i=y;i>=0;i--){
        // 北
        if(board[i][x] === 'p'){
            k+=1;
            console.log('北',k);
            break;
        }
        if(board[i][x] === 'B'){
            break;
        }
    }
    for(var i=x;i<board[y].length;i++){
        // 东
        if(board[y][i] === 'p'){
            k+=1;
            console.log('东',k);
            break;
        }
        if(board[y][i] === 'B'){
            break;
        }
    }
    for(var i=x;i>=0;i--){
        // 西
        if(board[y][i] === 'p'){
            k+=1;
            console.log('西',k);
            break;
        }
        if(board[y][i] === 'B'){
            break;
        }
    }
    return k
};