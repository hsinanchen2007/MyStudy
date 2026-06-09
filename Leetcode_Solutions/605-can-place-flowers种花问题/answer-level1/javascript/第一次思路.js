### 解题思路
首先判断n是否大于理论最大值，大于直接返回false，
本题本质是寻找数组中两个1之间连续的0，连续的0中能放置花的数量为 Math.floor((seriesZero - 1)/2)
特殊情况为 开头和结尾为0的情况
可以通过数组开始补0和结尾补0的方式，将这种特殊情况变成通常的情况。

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