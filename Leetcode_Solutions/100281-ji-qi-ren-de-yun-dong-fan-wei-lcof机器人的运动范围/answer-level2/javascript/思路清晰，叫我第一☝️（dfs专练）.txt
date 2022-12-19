### 解题思路

思路清晰，叫我第一☝️（dfs专练）

### 代码

```javascript
/**
 * @param {number} m
 * @param {number} n
 * @param {number} k
 * @return {number}
 */
var movingCount = function(m, n, k) {
    let step = {}

    let num = 0
    function dfs(i,j){
        if(i<0 || j<0 || i>=m || j>=n) return

        if(!step[`${i}|${j}`] && canMove(i,j,k)){
            step[`${i}|${j}`] = true
            num++

            dfs(i-1,j)
            dfs(i+1,j)
            dfs(i,j-1)
            dfs(i,j+1)
        }
    }
    dfs(0,0)
    return num
};
function canMove(i,j,k){
    let vali = i.toString().split('').reduce((a,b)=>{return Number(a) + Number(b)})
    let valj = j.toString().split('').reduce((a,b)=>{return Number(a) + Number(b)})
    if((Number(vali) + Number(valj)) <= k) return true
    return false
}
```