```js
function canPlaceFlowers (flowerbed, n) {
    if (n < 1) {
        return true
    }
    flowerbed.push(0)
    flowerbed.unshift(0)
    for (let i = 1; i < flowerbed.length - 1; i++) {
        var status = flowerbed[i]
        if (status === 1) {
            i++ // 不能种，并且它右边的一位也不能种，跳过一位
            continue
        }
        let leftEnable = flowerbed[i - 1] !== 1 // 这里不需要考虑边界条件
        let rightEnable = flowerbed[i + 1] !== 1
        if (leftEnable && rightEnable) {
            n-- // 种一颗花
            i++ // 跳过一位
            if (n <= 0) {
                break
            }
            continue
        }
        if (!rightEnable) {
            i = i + 2 // 如果是右边不符合条件，说明右边的是1，跳过1，在跳过1右边的一位
            continue
        }
    }
    return n <= 0
}
```