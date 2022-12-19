```js
var numEquivDominoPairs = function(dominoes) {
    let count = 0
    let map = new Map()
    for (let i = 0; i < dominoes.length; i++) {
        if (dominoes[i][0] > dominoes[i][1]) {
            [dominoes[i][0], dominoes[i][1]] = [dominoes[i][1], dominoes[i][0]]
        }
        let key = dominoes[i][0] + '-' + dominoes[i][1]
        if (!map.has(key)) {
            map.set(key,0)
        } else {
            map.set(key,map.get(key) + 1)
        }
    }
    for (let val of map.values()) {
        count += val * (val+1) / 2
    }
    return count
};
```
