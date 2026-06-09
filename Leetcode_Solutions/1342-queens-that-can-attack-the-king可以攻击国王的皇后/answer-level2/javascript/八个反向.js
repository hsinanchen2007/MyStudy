```js
/**
 * @param {number[][]} queens
 * @param {number[]} king
 * @return {number[][]}
 */
var queensAttacktheKing = function(queens, king) {
    const result = [], directions = [[-1, 0],[-1, 1], [0, 1], [1, 1], [1, 0], [1, -1], [0, -1], [-1, -1]]

    directions.forEach(([dx, dy]) => {
        const temp = findingQueenInDirection(dx, dy)
        if(temp) result.push(temp)
    })
    function findingQueenInDirection(dx, dy){
        let posX = king[0], posY = king[1]
        do{
            posX += dx
            posY += dy
            if(queens.find(queen => {
                return queen[0] === posX && queen[1] === posY
            })){
                return [posX, posY]
            }
        }while(posX >= 0 && posX <= 8 && posY >= 0 && posY <= 8)
        return null
    }
    return result
};
```