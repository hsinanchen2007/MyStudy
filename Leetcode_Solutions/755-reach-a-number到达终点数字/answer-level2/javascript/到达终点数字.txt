**思路：**

首先， 由于坐标轴是对称的，往左往右走的几率相等，因此可以只考虑右半轴。先递推一下可以知道:


|步数|        能到达的位置|
|---|---|
|1:|          1|
|2:|          3, 1|
|3:|          6, 4, 2, 0|
|4:|          10, 8, 6, 4, 0|
|5:|          15, 13, 11, 9, 7, 5, 3, 1|
|6:|          21, 19, 17, ...3, 1|
|n:|          (1+n)*n/2, ...|


可以看出来，每一步能到达的最大位置是上一步最大位置加上步数，而每一步所能达到的位置之间间隔都为2。
记f(n)为第n步能到达的位置，那么有：

```js
max(f(n)) = max(f(n-1)) + n
f(n) = [max(f(n)),  max(f(n)) - 2, max(f(n)) - 4, ....]
```

如果 target 可以在第 n 步达到，那么 target 一定小于等于 max(f(n)) 且 max(f(n)) 与 taget 同奇同偶。

```js
var reachNumber = function(target) {
    let sum = 0;
    let n = 0;
    target = Math.abs(target);
    while(sum < target || (target + sum) % 2 !== 0) {
        n++;
        sum += n;
    }
    return n
};
```

