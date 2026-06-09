/**
 * @param {number[]} piles
 * @param {number} H
 * @return {number}
 */
```javascript
var minEatingSpeed = function(piles, H) {
    for (let i = 1; i < Number.POSITIVE_INFINITY; i++) {
        if (!test(piles, i, H)) {
            continue;
        } else {
            return i;
        }
    }
    function test(piles, number, H) {
        let sum = 0;
        for (let j = 0; j < piles.length; j++) {
            sum += Math.ceil(piles[j] / number);
            if (sum > H) {
                return false;
            } else {
                if (j === piles.length - 1) {
                    return true;
                }
            }
        }
    }
};
```