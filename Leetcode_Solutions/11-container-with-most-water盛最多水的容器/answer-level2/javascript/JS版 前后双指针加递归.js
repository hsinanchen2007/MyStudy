
容器体积 =（尾索引指针 - 起始索引指针）* Math.min（arr[尾索引], arr[起始索引]）

每一次指针偏移都优先偏移较小值一方，以期望获得更大的容器体积，将得到的当前容器体积 和 历史最大体积比较 保留最大体积

当（尾索引指针 === 起始索引指针） 对比完成 返回历史最大体积。

```js
var maxArea = function(arr = []) {
    return loop(0, arr.length - 1, 0);
    function loop(start, end, max) {
        if (start === end) return max;
        var min = arr[start] > arr[end] ? arr[end] : arr[start];
        var sum = min * (end - start);
        if (sum > max) max = sum;
        if (arr[start] > arr[end]) return loop(start, end - 1, max);
        else return loop(start + 1, end, max);
    }
};
```
