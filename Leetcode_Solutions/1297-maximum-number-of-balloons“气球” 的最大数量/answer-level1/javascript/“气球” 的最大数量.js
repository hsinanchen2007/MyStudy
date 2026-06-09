```js
var maxNumberOfBalloons = function(text) {
    let map = new Map()
    let arr = text.split('')
    arr.forEach((item) => {
        if (/[ban]/.test(item)) {
            if (!map.has(item)) {
                map.set(item, 1)
            } else {
                map.set(item, map.get(item)+1)
            }
        } else if (/[lo]/.test(item)) {
            if (!map.has(item)) {
                map.set(item, 0.5)
            } else {
                map.set(item, map.get(item)+0.5)
            }
        }
    })
    let min = Math.min.apply(Math, ([...map.values()]))
    if (map.size < 5) {
    	return 0
    } else {
    	return parseInt(min)
    }
};
```
