执行用时 :92 ms, 在所有 JavaScript 提交中击败了82.85%的用户
内存消耗 :38 MB, 在所有 JavaScript 提交中击败了100.00%的用户

### 代码

```javascript
var spiralOrder = function (matrix) {
    // 空值校验
    if (!matrix.length) return []
    if (!matrix[0].length) return []

    let height = matrix.length;
    let width = matrix[0].length;
    let result = [];
    // 当前矩形左上角坐标(startX,startY)，右下角坐标(endX,endY)
    let startX = 0, startY = 0, endX = width - 1, endY = height - 1;
    while (endX >= startX && endY >= startY) {
        for (let i = startX; i <= endX; i++) {
            result.push(matrix[startY][i]);
        }
        for (let j = startY + 1; j <= endY; j++) {
            result.push(matrix[j][endX]);
        }
        for (let i = endX - 1; i >= startX; i--) {
            if (endY === startY) return result
            result.push(matrix[endY][i]);
        }
        for (let j = endY - 1; j >= startY + 1; j--) {
            if (startX === endX) return result
            result.push(matrix[j][startX]);
        }
        startX++;
        startY++;
        endX--;
        endY--;
    }
    return result
};
```