/**
 * @param {number} tomatoSlices
 * @param {number} cheeseSlices
 * @return {number[]}
 */
```javascript
var numOfBurgers = function(tomatoSlices, cheeseSlices) {
    if (tomatoSlices % 2 !== 0) {
        return [];
    }
    let x = tomatoSlices / 2 - cheeseSlices;
    let y = cheeseSlices - x;
    if (Number.isInteger(x) && x >= 0 && y >= 0) {
        return [x, y];
    } else {
        return [];
    }
};
```