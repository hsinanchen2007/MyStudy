### 解题思路
&emsp;&emsp;这题目类似主站的[221.最大正方形](https://leetcode-cn.com/problems/maximal-square/)，[85.最大矩形](https://leetcode-cn.com/problems/maximal-rectangle/)，[1139.最大的以 1 为边界的正方形](https://leetcode-cn.com/problems/largest-1-bordered-square/)。与最大正方形不一样的是本题只需要4条边能构成正方形就行，无需关注正方形内部状态，所以稍微复杂一些。因为是边与边的联系所以本题的解法类似于最大矩形，最大矩形求的是最大面积本题求的是最大边长，与1139的本质的都是一样的，只是返回值不一样。
&emsp;&emsp;使用dp数组存储每个点的所构成的长和宽，因为是正方形所以取其最小值进行遍历。只要遍历的最小值`range`大于之前保存的最大边且满足另外两边（横向和纵向）都等于`range`即`dp[i - range + 1][j][0] >= range && dp[i][j - range + 1][1] >= range`，便更新所求的最大边。

### 代码

```javascript
/**
 * @param {number[][]} matrix
 * @return {number[]}
 */
var findSquare = function(matrix) {
    let dp = new Array(matrix.length),
        size = 0,
        x = 0,
        y = 0;
    //初始化dp数组
    for(let i = 0; i < matrix.length; i++){
        dp[i] = [];
        for(let j = 0; j < matrix[i].length; j++){
            if(matrix[i][j] == 0){
                dp[i][j] = [1, 1]
                if(size == 0){
                    size = 1;
                    x = i;
                    y = j;
                }
            }else{
                dp[i][j] = [0, 0]
            }
        }
    }
    for(let i = 1; i < matrix.length; i++){
        if(matrix[i][0] == 0){
            dp[i][0][1] = Math.max(1, dp[i - 1][0][1] + 1);
        }
    }
    for(let i = 1; i < matrix[0].length; i++){
        if(matrix[0][i] == 0){
            dp[0][i][0] = Math.max(1, dp[0][i - 1][0] + 1);
        }
    }
    for(let i = 1; i < matrix.length; i++){
        for(let j = 1; j < matrix[i].length; j++){
            if(matrix[i][j] == 0){
                dp[i][j][0] = Math.max(1, dp[i][j - 1][0] + 1);
                dp[i][j][1] = Math.max(1, dp[i - 1][j][1] + 1);
                let range = Math.min(dp[i][j][0], dp[i][j][1]);
                for(; range > size; range--){
                    if(dp[i - range + 1][j][0] >= range && dp[i][j - range + 1][1] >= range){
                        size =  range;
                        x = i - range + 1;
                        y = j - range + 1;
                        break;
                    }
                }
            }
        }
    }
    return size == 0 ? [] : [x, y, size];
}
```