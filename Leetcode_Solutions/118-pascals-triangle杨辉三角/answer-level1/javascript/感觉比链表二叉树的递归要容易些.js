### 解题思路
![image.png](https://pic.leetcode-cn.com/8ccbb608f7b610747ddbf5c973d3ecdf794883b8760f10f2d38106639e7935fe-image.png)

“当前行”上面的三角 = generate(numRows - 1)。

### 代码

```javascript
/**
 * @param {number} numRows
 * @return {number[][]}
 */
var generate = function(numRows) {
    if (numRows === 0) return [];
    if (numRows === 1) return [[1]];
    if (numRows === 2) return [[1], [1, 1]];

    let prevTri = generate(numRows - 1),
        prevRow = prevTri[numRows - 2],
        curr = [];

    curr.push(1);
    prevRow.forEach((val, idx, arr) => {
        if (idx > 0) curr.push(val + arr[idx - 1]);
    });
    curr.push(1);
    prevTri.push(curr);

    return prevTri;
};
```