- 通过Map来记录类加过的行列以及值，最后用迭代器遍历一下
- 用普通对象也可以

```javascript
/**
 * @param {number} n
 * @param {number} m
 * @param {number[][]} indices
 * @return {number}
 */
var oddCells = function(n, m, indices) {
    const map = new Map()
    let count = 0
    indices.forEach((item, idx) => {
        for(let i = 0;i < m;i++) {
            let key = `${item[0]}-${i}`
            map.has(key) ? map.set(key, map.get(key) + 1) : map.set(key, 1)
        }
        for(let j = 0;j < n;j++) {
            let key = `${j}-${item[1]}`
            map.has(key) ? map.set(key, map.get(key) + 1) : map.set(key, 1)
        }
    })
    for (let item of map.values()) {
        item %2 === 1 && (count++)
    }
    return count
};
```
