### 解题思路
思路清晰，叫我第一☝️（dfs专练）

### 代码

```javascript
/**
 * @param {number[][]} image
 * @param {number} sr
 * @param {number} sc
 * @param {number} newColor
 * @return {number[][]}
 */
let oldc
let path
var floodFill = function(image, sr, sc, newColor) {
    oldc = image[sr][sc]
    path = {}
    dfs(image, sr, sc, newColor)
    return image
};

function dfs(image, i, j, newColor){
    if(i < 0 || j < 0 || i>=image.length || j>=image[0].length) return

    if(image[i][j] === oldc && !path[`${i}|${j}`]){
        path[`${i}|${j}`] = 1
        image[i][j] = newColor
        dfs(image, i-1, j, newColor)
        dfs(image, i+1, j, newColor)
        dfs(image, i, j-1, newColor)
        dfs(image, i, j+1, newColor)
    }
}
```