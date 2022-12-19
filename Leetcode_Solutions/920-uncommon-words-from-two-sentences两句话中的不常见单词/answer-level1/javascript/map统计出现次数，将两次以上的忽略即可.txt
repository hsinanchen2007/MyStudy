```js
/**
 * @param {string} A
 * @param {string} B
 * @return {string[]}
 */
var uncommonFromSentences = function (A, B) {
    const arrA = A.split(' '), arrB = B.split(' '), allArr = [...arrA, ...arrB]
    let map = new Map(), result = []
    allArr.forEach(d => {
        if (map.has(d)) {
            map.set(d, map.get(d) + 1)
        } else {
            map.set(d, 1)
        }
    })
    map.forEach((d, k) => {
        if (d === 1) {
            result.push(k)
        }
    })
    return result
};
```
