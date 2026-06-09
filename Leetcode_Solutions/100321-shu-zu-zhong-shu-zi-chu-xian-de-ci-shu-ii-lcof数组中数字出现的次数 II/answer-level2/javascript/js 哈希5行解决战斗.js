哈希5行解决战斗
```js
var singleNumber = function(nums) {
    const temp = new Set();
    return Array.from(nums.reduce((t, num) => {
        !t.has(num) ? t.add(num) :(temp.has(num) ? t.delete(num) : temp.add(num))
        return t;
    }, new Set()));
};
```
