```javascript
var numRookCaptures = function(board) {
    let [sum, Rx, Ry] = [0];
    let found = false;
    const [dx, dy] = [[1, 0, -1, 0], [0, 1, 0, -1]];
    for (var i = 0; i < 8; i++) {
        for (var j = 0; j < 8; j++) {
            if (board[i][j] === 'R') {
                Rx = i;
                Ry = j;
                found = true;
                break;
            }
        }
        if (found) break;
    }
    for (var i = 0; i < 4; i++) {
        for (var step = 1;; step++) {
            var posX = Rx + step * dx[i];
            var posY = Ry + step * dy[i];
            if (posX <= 0 || posX >= 8 || posY <= 0 || posY >= 8 || board[posX][posY] === 'B') break;
            if (board[posX][posY] === 'p') {
                sum++;
                break;
            }
        }
    }
    return sum;
}
```