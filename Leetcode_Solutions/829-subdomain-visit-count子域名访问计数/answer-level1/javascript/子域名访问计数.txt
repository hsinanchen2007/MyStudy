```js
var subdomainVisits = function(cpdomains) {
    let map = new Map();
    for (let i = 0; i < cpdomains.length; i++) {
        let [num, url] = cpdomains[i].split(/\s+/);
        // 存放所有域名
        var items = [url];
        for (let j = 0; j < url.length; j++) {
            if (url[j] === '.') {
                items.push(url.substr(j+1))
            }
        }
        items.forEach((item) => {
            if (!map.has(item)) {
                map.set(item, +num)
            } else {
                map.set(item, map.get(item) + +num)
            }
        })
    }
    let res = [];
    for (let [key, val] of map) {
        res.push(`${val} ${key}`)
    }
    return res
};
```
