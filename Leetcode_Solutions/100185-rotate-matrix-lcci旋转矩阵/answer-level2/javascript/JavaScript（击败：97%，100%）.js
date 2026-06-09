#### 思路
1. 遍历矩阵，依次将列变成行；
2. 追加到原数组上；
3. 删除前面的行。
![截屏2020-04-07 上午9.46.40.png](https://pic.leetcode-cn.com/9f76e5cb700b8e33f551275b295e057953d62a3813dc66b9b61482c3b2df70c0-%E6%88%AA%E5%B1%8F2020-04-07%20%E4%B8%8A%E5%8D%889.46.40.png)

#### 代码
```
var rotate = function(matrix) {
    let len = matrix.length;
    for (let col = 0; col < len; col++) {
        // 保存列
        let temp = [];
        for (let row = len - 1; row >= 0; row--) {
            temp.push(matrix[row][col]);
        }
        // 追加lie
        matrix.push(temp);
    }
    // 删除前面的行
    matrix.splice(0, len);
};
```
