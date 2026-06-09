
*法一*

```js
var judgeCircle = function(moves) {
    let countR = 0;
    let countU = 0;
    let len = moves.length;
    for (let i = 0; i < len; i++) {
        if (moves[i] == 'R') {
            countR++
        } else if (moves[i] == 'L') {
            countR--
        } else if (moves[i] == 'U') {
            countU++
        } else {
            countU--
        }
    }
    return countR == 0 && countU == 0;
};
```

*法二*

```js
var judgeCircle = function(moves) {
    // 判断 L.count === R.count && U.count === D.count
    return moves.split('L').length === moves.split('R').length && moves.split('U').length === moves.split('D').length
};
```