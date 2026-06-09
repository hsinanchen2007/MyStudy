### 解题思路
这道题用到DFS（深度优先搜索）的概念；
先判断是否需要染色，然后定义保存老颜色，然后在合法坐标内上下左右搜索判断是否为老颜色，进行递归运算。

### 代码

```javascript
/**
 * @param {number[][]} image
 * @param {number} sr
 * @param {number} sc
 * @param {number} newColor
 * @return {number[][]}
 */
var floodFill = function(image, sr, sc, newColor) {
    if(image[sr][sc]===newColor) return image;
    let r=image.length;
    let c=image[0].length;
    let oldColor=image[sr][sc];
    let dfs=(x,y)=>{
        image[x][y]=newColor;
        if(x>0&&image[x-1][y]===oldColor) dfs(x-1,y);
        if(y>0&&image[x][y-1]===oldColor) dfs(x,y-1);
        if(x<r-1&&image[x+1][y]===oldColor) dfs(x+1,y);
        if(y<c-1&&image[x][y+1]===oldColor) dfs(x,y+1);
    }
    dfs(sr, sc);
    return image;
};
```