### 解题思路
sh

### 代码

```javascript
/**
 * @param {number[]} flowerbed
 * @param {number} n
 * @return {boolean}
 */
var canPlaceFlowers = function(flowerbed, n) {
    let l = flowerbed.length;
    // 大于理论最大值直接返回false
    if(n > (l.length + 1)/2){
        return false;
    }
    // 放置本质是寻找连续的0，看看有多个连续的0
    // 连续的0能放置的数量为 (seriesLength -1) /2
    var actualCount = 0;
    var seriesZero = 0;
    // 当数组过大时，操作数组耗费的时间过长。此处待优化
    flowerbed.push(0)
    flowerbed.unshift(0)
    l += 2
    for(var i = 0;i<l;i++) {
        if(flowerbed[i] || i == l-1){
            if(i == l-1) seriesZero++;
            let flower = Math.floor((seriesZero - 1)/2);
            flower = flower > 0 ? flower: 0;
            actualCount += flower;
            seriesZero = 0;
        } else {
            seriesZero++
        }
    }
    return actualCount >= n;

};
```