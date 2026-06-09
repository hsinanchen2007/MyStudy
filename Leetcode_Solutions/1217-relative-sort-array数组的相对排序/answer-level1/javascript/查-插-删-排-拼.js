执行用时 : 88 ms, 在所有 JavaScript 提交中击败了 47.86% 的用户
内存消耗 : 34.8 MB, 在所有 JavaScript 提交中击败了 100.00% 的用户

虽然时间性能差了一些，但是菜鸡第一次写出 100%，还是纪念分享一下

```javascript []
var relativeSortArray = function(arr1, arr2) {
    var oldOrder = [];
    for (let old of arr2) {
        let pushee = 0;
        while (pushee != arr1.length) {
            if (arr1[pushee] === old) {
                oldOrder.push(old);
                arr1.splice(pushee, 1);
            } else {
                ++pushee;
            }
        }
    }
    return oldOrder.concat(arr1.sort((x, y) => { return x-y; }));
};
```
