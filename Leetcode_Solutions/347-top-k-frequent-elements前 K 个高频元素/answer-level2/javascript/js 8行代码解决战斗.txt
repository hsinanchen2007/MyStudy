js 8行代码解决战斗
```js
var topKFrequent = function(nums, k) {
    const record = nums.reduce((t, i) => {
        t[i] = t[i] ? t[i] + 1 : 1;
        return t;
    }, {});
    return Object.entries(record)
        .sort((a, b) => b[1] - a[1])
        .slice(0, k)
        .map(entry => +entry[0]);
};
```
