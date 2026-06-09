一通分析：

选择 k (k <= n) 道菜时的策略

1. 选数值最大的 k 道
    证明略
2. 这 k 道菜按非降序排列
    证明略

解法：排序，然后从最大满意值的一道菜往制作顺序里添

```js []
/**
 * @param {number[]} satisfaction
 * @return {number}
 */
var maxSatisfaction = function (satisfaction) {
    satisfaction.sort((a, b) => b - a)
    var sum = 0, val = 0, max = 0;
    for (var x of satisfaction){
        sum += x;
        val += sum;
        max = Math.max(max, val);
    }
    return max;
}
```
```js []
/**
 * @param {number[]} satisfaction
 * @return {number}
 */
var maxSatisfaction = function (satisfaction) {
    return satisfaction.sort((a, b) => b - a)
        .reduce((a, b) => [...a, b + (a[a.length - 1]||0)], []) // sum
        .reduce((a, b) => [...a, b + (a[a.length - 1]||0)], []) // val
        .reduce((a, b) => Math.max(a,b),0)      
};
```

PS
满意程度有序情况下可以证明 
总满意值的边际效用的边际效用是单调递减的（从解答2的过程可以看出）
因此 总满意值对 k 有唯一极值点
（但是边际效用没有O(1)的求法
