用相邻矩阵把图的关系记录下来，然后把能推断出来的点都推断出来。
如果需要很多返回的解，比较有优势。

```js
/**
 * @param {string[][]} equations
 * @param {number[]} values
 * @param {string[][]} queries
 * @return {number[]}
 */
var calcEquation = function(equations, values, queries) {
   // Graph Adjacency Matrix
    const matrix = {};
    equations.forEach((pair, i) => {
        if (!matrix[pair[0]]) matrix[pair[0]] = {};
        if (!matrix[pair[1]]) matrix[pair[1]] = {};
        matrix[pair[0]][pair[1]] = values[i];
        matrix[pair[1]][pair[0]] = 1 / values[i];
    });
    const keys = Object.keys(matrix);
    keys.forEach(x => {
        keys.forEach(y => {
            if (matrix[x][y]) {
                keys.forEach(xy => {
                    if (matrix[y][xy]) matrix[x][xy] = matrix[y][xy] * matrix[x][y];
                })
            }
        })
    })
    return queries.map(query => 
        matrix[query[0]] && matrix[query[0]][query[1]] ? matrix[query[0]][query[1]] : -1);
};
```