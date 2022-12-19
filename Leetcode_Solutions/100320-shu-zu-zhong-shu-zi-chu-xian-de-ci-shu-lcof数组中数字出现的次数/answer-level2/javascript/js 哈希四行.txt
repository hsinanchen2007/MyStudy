哈希四行解决战斗
```js
var singleNumbers = function(nums) {
    return Array.from(nums.reduce((t, num) => {
        t.has(num) ? t.delete(num) : t.add(num);
        return t;
    }, new Set()));
};
```
