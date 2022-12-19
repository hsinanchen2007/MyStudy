```js
var mostCommonWord = function(paragraph, banned) {
    let paragraphArr = paragraph.toLowerCase().replace(/[!?',;\.]/g,' ').split(/[\s]+/);
    let map = new Map();
    let len = paragraphArr.length
    for (let i = 0; i < len; i++) {
        if(banned.includes(paragraphArr[i]) || paragraphArr[i] === '') {
            continue
        }
        if (!map.has(paragraphArr[i])) {
            map.set(paragraphArr[i], 1)
        } else {
            map.set(paragraphArr[i], map.get(paragraphArr[i]) + 1)
        }
    }
    let maxCount = Math.max.apply(Math, [...map.values()]);
    let res = '';
    map.forEach((val, key) => {
        if (val === maxCount) {
            res = key
            return
        }
    })
    return res
};
```

