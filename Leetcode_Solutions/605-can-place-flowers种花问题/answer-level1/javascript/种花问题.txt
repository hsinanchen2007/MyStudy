防御式编程思想：在 flowerbed 数组两端各增加一个 0， 这样处理的好处在于不用考虑边界条件，任意位置处只要连续出现三个 0 就可以栽上一棵花。

```js
var canPlaceFlowers = function(flowerbed, n) {
    flowerbed.unshift(0)
    flowerbed.push(0)
    let count = 0;
    let len = flowerbed.length;
    for (let i = 0; i < len; i++) {
        if (flowerbed[i-1] === 0 && flowerbed[i] === 0 && flowerbed[i+1] === 0) {
            flowerbed[i] = 1;
            count++
        }
    }
    return count >= n;
};
```

