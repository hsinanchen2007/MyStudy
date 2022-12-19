### 解题思路
此处撰写解题思路
暴力法竟然还能击败这么多  很好奇将别人是怎么做的
### 代码

```javascript
/**
 * @param {number[][]} matrix
 * @param {number} target
 * @return {boolean}
 */
var findNumberIn2DArray = function(matrix, target) {
    for(let i=0;i<matrix.length;i++){
        for(let j=0;j<matrix[i].length;j++){
            if(matrix[i][j]==target){
                return true
            }
        }
    }
    return false
};
```![image.png](https://pic.leetcode-cn.com/e1c29285a84bc780b934929af457b297b36fd233768cd3cc5c0dd679ab9f579b-image.png)

