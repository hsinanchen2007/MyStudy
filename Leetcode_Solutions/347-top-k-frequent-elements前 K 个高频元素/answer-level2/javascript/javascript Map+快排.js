```js
var topKFrequent = function (nums, k) {
    const map = new Map();
    const list = [];
    for (let item of nums) {
        map.set(item, (map.get(item) || 0) + 1);
    }
    for (let entires of map) {
        list.push({
            value: entires[0],
            count: entires[1]
        });
    }
    list.sort((a, b) => b.count - a.count);
    const result = [];
    for (let i = 0; i < k; i++) {
        result.push(list[i].value);
    }
    return result;
};
```