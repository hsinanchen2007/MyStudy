```js
var longestPalindrome = function(s) {
    let map = new Map();
    let num = 0;
    let single = false;
    for (let i = 0; i < s.length; i++) {
        let val = map.get(s[i]);
        if (!val) {
            map.set(s[i], 1)
        } else {
            map.set(s[i], val + 1)
        }
    }
    map.forEach( (item, index) => {
        if (item % 2 === 0) {
            num += item
        } else {
            single = true;
            if (item > 1) {
                num += item - 1;
            }
        }
    })
    if (single) {
        num += 1;
    }
    return num;
};
```
