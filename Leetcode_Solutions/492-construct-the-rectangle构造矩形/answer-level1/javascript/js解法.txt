
#### 思路
- 设宽为变量，从面积的开方起往下找，能整除的第一个就是相差最近的高和宽


```
/**
 * @param {number} area
 * @return {number[]}
 */
var constructRectangle = function (area) {
    let M = Math.floor(Math.sqrt(area))
    while (area % M) {
        M -= 1
    }
    return [area / M, M]
};
```
