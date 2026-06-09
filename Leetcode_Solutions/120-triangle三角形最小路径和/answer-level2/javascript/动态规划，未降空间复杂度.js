### 解题思路
最优子结构，加上路径问题，想到动态规划
动态规划就是从下向上考虑
动态转移方程  F(i , j) = MIN( F(i +1 , j) , F(i +1, j+1) ) + F(i , j)

### 代码

```javascript
/**
 * @param {number[][]} triangle
 * @return {number}
 */
var minimumTotal = function(triangle) {
    if(triangle.length ==0 || triangle ==null){return 0}
    let arr = new Array(triangle.length +1).fill(new Array(triangle.length +1).fill(0))
    for (let i = triangle.length -1; i >=0 ; i--){
        for(let j = 0; j< triangle[i].length ;j++)
        arr[i][j] = Math.min(arr[i+1][j] , arr[i+1][j+1]) + triangle[i][j]
    }
    return arr[0][0]
};
```