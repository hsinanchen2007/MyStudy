

``` javascript
    if (typeof s !== 'string') return false;
    let startIndex = 0;
    let endIndex = 0;
    const map = {};
    let maxLength = 0
    for (let i = endIndex, l = s.length; i < l; i++) {
        const c = s[i];
        const beenIndex = map[c]
        let hasBeen = (beenIndex || beenIndex === 0) && beenIndex >= startIndex
        if (hasBeen) {
            startIndex = beenIndex + 1;
        }
        map[c] = i;
        endIndex++
        maxLength = Math.max(maxLength, endIndex - startIndex)
    }
    return maxLength
```
