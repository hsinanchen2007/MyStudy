### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} flowerbed
 * @param {number} n
 * @return {boolean}
 */
var canPlaceFlowers = function(flowerbed, n) {
            flowerbed.unshift(0);
            flowerbed.push(0);
            for (var i = 1; i < flowerbed.length - 1; i++) {
                if (flowerbed[i] == 0 && flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0) {
                    flowerbed[i] = 1;
                    n--;
                } else {
                    flowerbed[i] = flowerbed[i];
                }
            }
            return n <= 0;
        }

```