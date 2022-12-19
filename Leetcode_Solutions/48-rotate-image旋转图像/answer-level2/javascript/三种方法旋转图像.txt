### 解题思路
### 方法一
先将矩阵转置，在对转置后的矩阵每行进行翻转

### 代码

```javascript
/**
 * @param {number[][]} matrix
 * @return {void} Do not return anything, modify matrix in-place instead.
 */
var rotate = function(matrix) {
    for(var i=0;i<matrix.length;i++){
        for(var j=i+1;j<matrix.length;j++){
            var temp = matrix[i][j];
            matrix[i][j] = matrix[j][i]
            matrix[j][i] = temp
        }
    }
            
    for(var i=0;i<matrix.length;i++){
        matrix[i].reverse()
    }
};
```
![image.png](https://pic.leetcode-cn.com/7a5a3e808e7db7bfd17cd9297a66f36843e8855ad866c12c451a8922161dab71-image.png)

### 方法二
先将矩阵整个翻转，在对矩阵转置

```javascript
/**
 * @param {number[][]} matrix
 * @return {void} Do not return anything, modify matrix in-place instead.
 */
var rotate = function(matrix) {
    matrix.reverse() //[[1],[2],[3]] => [[3],[2],[1]]
    for(var i=0;i<matrix.length;i++){
        for(var j=i+1;j<matrix.length;j++){
            var temp = matrix[i][j];
            matrix[i][j] = matrix[j][i]
            matrix[j][i] = temp
        }
    }
};
```
![image.png](https://pic.leetcode-cn.com/7b01df68b4714e823e1408d8b0a2b7a2ccc29e491ef682d18fed20e62f1bac77-image.png)

###方法三
把矩阵看为一层一层的，由外层到内层，这是外循环。每一层看成四个小的块交换位置，这是内循环。
![image.png](https://pic.leetcode-cn.com/ba107d45bc0e0c2debd6dc042aee84fd9e5317ab098e4b55537e24cde9dbdc55-image.png)

```javascript
var rotate = function(matrix) {
    var len = matrix.length;
    //循环几层
    for(var i=0;i<len/2;i++){
        //每层要移动的小数组的宽度循环
        for(var j=i;j<len-1-i;j++){
            var temp = matrix[i][j]
            matrix[i][j] = matrix[len-1-j][i]
            matrix[len-1-j][i] = matrix[len-1-i][len-1-j]
            matrix[len-1-i][len-1-j] = matrix[j][len-1-i]
            matrix[j][len-1-i] = temp;
        }
    }

};
```
![image.png](https://pic.leetcode-cn.com/bd3c0e00092d3ea70dc827eff57eee1733f9b2370b10940dac7888c4ad88f37f-image.png)
