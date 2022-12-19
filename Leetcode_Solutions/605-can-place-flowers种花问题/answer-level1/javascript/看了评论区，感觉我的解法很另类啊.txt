我这是强行让数组第一个元素置为 1
如果遇到
- 连续两个 0，就把第二个 0 置为 1
- 连续两个 1，就把上一个 1 置为 0 （*ps: 题目注意有提到： 数组内已种好的花不会违反种植规则， 所以违反规则的只能是自己， 所以把上一次取消的操作回撤*）

说实话一开始根本没往 **每 3 个 0 中间种一朵花** 这个思路上走...⊙﹏⊙b汗

```
/**
 * @param {number[]} flowerbed
 * @param {number} n
 * @return {boolean}
 */
var canPlaceFlowers = function(flowerbed, n) {
    if (n === 0) return true
    
    if (flowerbed[0] === 0) {
        flowerbed[0] = 1
        n--
    }
    for (let i = 1, len = flowerbed.length; i < len; i++) {
        if (flowerbed[i] ^ flowerbed[i - 1] === 0) {
            if (flowerbed[i] === 1) {
                flowerbed[i - 1] = 0
                n++
            } else {
                if (n === 0) return true
                
                flowerbed[i] = 1
                n--
            }
        }
    }
    return n === 0
};
```
