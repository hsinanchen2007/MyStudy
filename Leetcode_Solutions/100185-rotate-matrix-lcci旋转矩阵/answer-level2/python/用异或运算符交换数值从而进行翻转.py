首先，找规律可知，和点 `[i][j]` 有关的旋转点分别为：
![image.png](https://pic.leetcode-cn.com/0c715932e31800cfef1fa7c75ef51b17373cc9ae366d630d52412e0376faa069-image.png)
显然这四个点是循环交换的。

而由两个数a、b的交换方法：
```
var temp = a;
a = b;
b = temp;
```
可以拓展得到一系列数循环交换的方法：
```
var temp = a;
a = b;
b = c;
c = d;
...
z = temp;
```
所以可以得到这题的解法：
```javascript []
/**
 * @param {number[][]} matrix
 * @return {void} Do not return anything, modify matrix in-place instead.
 */
var rotate = function(matrix) {
    var N = matrix.length;
    var row = Math.floor(N / 2);
    var col = Math.ceil(N / 2);
    for(var i = 0; i < row; i++){
        for(var j = 0; j < col; j++){
            var temp = matrix[i][j];
            matrix[i][j] = matrix[N - j - 1][i];
            matrix[N - j - 1][i] = matrix[N - i - 1][N - j - 1];
            matrix[N - i - 1][N - j - 1] = matrix[j][N - i - 1];
            matrix[j][N - i - 1] = temp;
        }
    }
};
```
```python []
print('Hello world!')
```
```ruby []
puts 'Hello world!'
```

另，参考不需要第三个变量而采用异或运算符的交换方法：
```
a = a ^ b;
b = a ^ b;
a = a ^ b;
```
也可以有如下解，虽然可读性差了点，但是更符合题目的 `不占用额外内存空间` 的描述

```javascript []
/**
 * @param {number[][]} matrix
 * @return {void} Do not return anything, modify matrix in-place instead.
 */
var rotate = function(matrix) {
    var N = matrix.length;
    var row = Math.floor(N / 2);
    var col = Math.ceil(N / 2);
    for(var i = 0; i < row; i++){
        for(var j = 0; j < col; j++){
            // 90度旋转，[i, j] 最后都是到 [j, N - 1 - i] 位置
            matrix[i][j]        = matrix[i][j] ^ matrix[j][N - 1 -i];
            matrix[j][N - 1 -i] = matrix[i][j] ^ matrix[j][N - 1 -i];
            matrix[i][j]        = matrix[i][j] ^ matrix[j][N - 1 -i];

            // 然后，原来的[N - 1 -j, i] 也会旋转到 [i, j] 的位置
            matrix[N - 1 - j][i] = matrix[N - 1 - j][i] ^ matrix[i][j];
            matrix[i][j]         = matrix[N - 1 - j][i] ^ matrix[i][j];
            matrix[N - 1 - j][i] = matrix[N - 1 - j][i] ^ matrix[i][j];

            // 最后再交换一下 [N - 1 - i, N - 1 - j] 和 [N - 1 - j][i]
            matrix[N - 1 - i][N - 1 - j] = matrix[N - 1 - i][N - 1 - j] ^ matrix[N - 1 -j][i];
            matrix[N - 1 -j][i]          = matrix[N - 1 - i][N - 1 - j] ^ matrix[N - 1 -j][i];
            matrix[N - 1 - i][N - 1 - j] = matrix[N - 1 - i][N - 1 - j] ^ matrix[N - 1 -j][i];
        }
    }
};
```
```python []
print('Hello world!')
```
```ruby []
puts 'Hello world!'
```

