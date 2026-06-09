```
/**
 * @param {number[]} hand
 * @param {number} W
 * @return {boolean}
 */
var isNStraightHand = function(hand, W) {
    if(hand.length % W !== 0) return false
    let g = []
    hand.sort((a, b) => a - b)
    while(hand.length) {
        if(g.length === 0) {
            g.push(hand.shift())
        } else {
            let i = 0
            const last = g[g.length - 1]
            for(let i = 0;i < hand.length;i++) {
                if(hand[i] === last +1) {
                    g.push(hand[i])
                    hand.splice(i, 1)
                    break
                }
            }
            if(last === g[g.length - 1]) return false
        }
        if(g.length === W) g = []
    }
    return true
};
```
