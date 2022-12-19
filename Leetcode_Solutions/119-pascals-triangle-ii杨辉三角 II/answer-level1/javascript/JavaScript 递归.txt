```
/**
 * @param {number} rowIndex
 * @return {number[]}
 * 递归 动态规划，先获取 第 k - 1 行的数据
 */
var getRow = function(rowIndex) {
    if (rowIndex === 0)
        return [1];
    if (rowIndex === 1)
        return [1, 1];
    if (rowIndex === 2)
        return [1, 2, 1];
    if (rowIndex === 3)
        return [1, 3, 3, 1];
    let preRow = getRow(rowIndex - 1);
    let res = [1];
    for(let i = 0; i < preRow.length - 1; i++) {
        res.push(preRow[i] + preRow[i + 1]);
    }
    res.push(1);
    return res;
};


```