
```
/*
* 在首位都加上一个0 这样就不用考虑边界问题
* */
var canPlaceFlowers = function (flowerbed, n) {
    flowerbed.push(0);
    flowerbed.unshift(0);
    for (let i = 1; i < flowerbed.length - 1; i++) {
        if (flowerbed[i - 1] == 0 && flowerbed[i] == 0 && flowerbed[i + 1] == 0) {
            n--;
            i++;
        }
    }
    return n <= 0 ? true : false;
```