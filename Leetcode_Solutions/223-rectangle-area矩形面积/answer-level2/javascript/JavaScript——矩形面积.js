### 解题思路
第一遍被题目图片影响，没有考虑不重叠的情况，遂反思应先判断矩形是否重叠再做运算

### 代码

```javascript
/**
 * @param {number} A
 * @param {number} B
 * @param {number} C
 * @param {number} D
 * @param {number} E
 * @param {number} F
 * @param {number} G
 * @param {number} H
 * @return {number}
 */
var computeArea = function(A, B, C, D, E, F, G, H) {
   var min = Math.min,
            max = Math.max,
            abs = Math.abs;
        // 需要考虑没有重叠和有重叠的情况
        if (C <= E || A >= G) {
            return ((D - B) * (C - A) + (H - F) * (G - E));
        } else {
            if (D <= F || H <= B) {
                return ((D - B) * (C - A) + (H - F) * (G - E));
            } else {
                return ((D - B) * (C - A) + (H - F) * (G - E) - abs((min(D, H) - max(B, F)) * (min(C, G) -
                    max(A,
                        E))));
            }
        }

};
```