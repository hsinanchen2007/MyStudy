### 解题思路
原地旋转
如图，只需要将上三角区域中的每个点进行依次旋转即可（包含三角形的左边界但不包含三角形的右边界）
![image.png](https://pic.leetcode-cn.com/9a41562966d2c8e31760b753f9755c6b6d5726ad80d24583ed70228ab7d0bfb0-image.png)


### 代码

```javascript
/**
 * @param {number[][]} matrix
 * @return {void} Do not return anything, modify matrix in-place instead.
 */
var rotate = function(matrix) {
    let N=matrix.length - 1;
    //两层for循环的条件就是将上三角区域限定出来
    for(let i = 0 ; i < matrix.length / 2 ; i ++){
        for(let  j = i ; j < matrix[0].length - i -1 ; j ++){
           // 对该三角区域中的每个点 与 其他三个区域中的每个点 依次进行交换即可完成旋转
            let tem = matrix[i][j];
            matrix[i][j] = matrix[N-j][i];
            matrix[N-j][i] = matrix[N-i][N-j];
            matrix[N-i][N-j] =  matrix[j][N-i];
            matrix[j][N-i]= tem;
           // console.log(matrix);
        }
    }
    return matrix;
};
```