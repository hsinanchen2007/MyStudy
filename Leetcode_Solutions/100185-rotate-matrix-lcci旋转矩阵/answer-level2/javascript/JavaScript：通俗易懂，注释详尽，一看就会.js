### 题意分析
数组旋转90°，意味着什么？

不如直接画图分析下。

![旋转前.png](https://pic.leetcode-cn.com/0e6587da7ddb39f87c370f38544da9cd91e8e4abce6c0882d7df76c93d3e5433-%E6%97%8B%E8%BD%AC%E5%89%8D.png) (90°旋转)===> ![旋转后.png](https://pic.leetcode-cn.com/1a00a28931a22b170f2dd05279bca47821a69fe451fc7b54823e38d53a126538-%E6%97%8B%E8%BD%AC%E5%90%8E.png)

很明显：
- 第1行变成了第3列，行中元素位置与列中元素位置一致
- 第2行变成了第2列，行中元素位置与列中元素位置一致
- 第3行变成了第1列，行中元素位置与列中元素位置一致

即：矩阵中第`i`行的第`j`个元素，在旋转后，它出现在**倒数**第`i`列的第`j`个位置。

### 逻辑分析
结合题意，我们需要解决以下两个问题：
- 无额外数组
- 翻转实现

##### 无额外数组
![1586226858(1).png](https://pic.leetcode-cn.com/513563f4d026365b6647d54484667bceab95609213387946a988e937d94aca7e-1586226858\(1\).png)

试想，如果可以把数组`matrix`构造成这个样子，即翻转后的数组附加在原数组上，最后再移除红框内的元素，是否就可以实现无额外数组了？

很明显，原始`matrix`数组是`N*N`，那么，只需**每行**截取起始位（`0`）到终止位（数组长度`N`），就可以剩下最终需要的数组内容了。

利用伪代码实现的话，大致如下：

```
for(let i = 0; i < 数组长度; i++) {
    matrix[i].splice(0, 数组长度);
}
```

##### 翻转实现
由于`matrix`是二维数组，故必然需要双重循环才能遍历到每个元素。

那么是不是可以在遍历的是否做点文章呢？

前文已知，矩阵中第`i`行的第`j`个元素，在旋转后，它出现在**倒数**第`i`列的第`j`个位置。

如何才能用代码实现这句话？

可以参考下面的伪代码：
```
// 反向遍历最外层数组，即矩阵的行
for(let i = 数组长度 - 1; i >= 0; i--) {
    for(let j = 0; j < 数组长度; j++) {
        // 倒数第N行变成正数第N列
        matrix[j].push(matrix[i][j]);
    }
}
```

### 代码实现

以下是具体的代码实现：
```
/**
 * @param {number[][]} matrix
 * @return {void} Do not return anything, modify matrix in-place instead.
 */
var rotate = function(matrix) {
    const length = matrix.length;

    for(let i = length - 1; i >= 0; i--) {
        for(let j = 0; j < length; j++) {
            matrix[j].push(matrix[i][j]);
        }
    }

    for(let i = 0; i < length; i++) {
        matrix[i].splice(0, length);
    }
};
```




