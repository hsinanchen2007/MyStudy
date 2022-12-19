### 解题思路
思路清晰，叫我第一☝️（dfs专练）

### 代码

```javascript
/**
 * @param {number[][]} land
 * @return {number[]}
 */
let res
let area
var pondSizes = function(land) {
    res = []
    for(let i = 0; i< land.length; i++){
        for(let j = 0; j< land[0].length; j++){
            if(land[i][j] == 0){
                area = 0
                dfs(land, i, j)
                res.push(area)
            }
        }
    }
    return res.sort((a, b)=> (a-b))
};

function dfs(land, i, j){
    if(i<0 || j < 0 || i>=land.length || j>=land[0].length) return
    if(land[i][j] == 0){
        land[i][j] = 1
        area++
        dfs(land, i-1,j)
        dfs(land, i+1,j)
        dfs(land, i,j-1)
        dfs(land, i,j+1)
        dfs(land, i-1,j-1)
        dfs(land, i-1,j+1)
        dfs(land, i+1,j-1)
        dfs(land, i+1,j+1)
    }
}
```