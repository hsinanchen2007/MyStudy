```
var numMovesStones = function(a, b, c) {
    let arr = [a, b, c]
    arr.sort((a, b) => a - b)
    a = arr[0]
    b = arr[1]
    c = arr[2]
    let maxMoves;
    let minMoves;
    if (b-a == 1 && c-b == 1) {
        maxMoves = 0
    } else if (b-a == 1 && c-b != 1) {
        maxMoves = c-b-1
    } else if (b-a != 1 && c-b == 1){
        maxMoves = b-a-1
    } else {
        maxMoves = c-a-2
    }

    if (b-a == 1 && c-b == 1) {
        minMoves = 0
    } else if (b-a == 1 || c-b == 1 || b-a == 2 || c-b == 2) {
        minMoves = 1
    } else {
        minMoves = 2
    }
    return [minMoves, maxMoves]
}
```
