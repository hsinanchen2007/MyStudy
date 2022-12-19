

### 代码

```javascript
var tictactoe = function(moves) {
    let A = [];
    let B = [];
    let isAWin = false
    let isBWin = false
    let len = moves.length
    for (let i = 0; i < len; i++) {
        if (i % 2 == 0) {
            A.push(moves[i])
        } else {
            B.push(moves[i])
        }
    }
    let Alen = A.length
    let Blen = B.length
    if (Alen >= 3) {
        for (let i = 0; i < Alen; i++) {
            for (let j = 0; j < Alen; j++) {
                if (j !== i) {
                    for (let k = 0; k < Alen; k++) {
                        if (k !== i && k !== j) {
                            if ((A[j][1] - A[i][1]) * (A[k][0] - A[j][0]) == (A[j][0] - A[i][0]) * (A[k][1] - A[j][1])) {
                                isAWin = true
                                break;
                            }
                        }
                    }
                }
            }
        } 
    }
    if (Blen >= 3) {
        for (let i = 0; i < Blen; i++) {
            for (let j = 0; j < Blen; j++) {
                if (j !== i) {
                    for (let k = 0; k < Blen; k++) {
                        if (k !== i && k !== j) {
                            if ((B[j][1] - B[i][1]) * (B[k][0] - B[j][0]) == (B[j][0] - B[i][0]) * (B[k][1] - B[j][1])) {
                                isBWin = true
                                break;
                            }
                        }
                    }
                }
            }
        } 
    }
    if (isAWin) {
        return 'A'
    } else if (isBWin) {
        return 'B'
    } else if (len == 9) {
        return 'Draw'
    } else {
        return 'Pending'
    }
};
```