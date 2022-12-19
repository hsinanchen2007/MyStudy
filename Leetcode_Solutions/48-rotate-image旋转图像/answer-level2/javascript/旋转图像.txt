### 解题思路
![image.png](https://pic.leetcode-cn.com/401776028c93960346571e669666eca4bf4474d0c851e8338fb824d12b3c6ae9-image.png)   

啥思想也没有，就是一个纯空间变幻

### 代码

```javascript
/**
 * @param {number[][]} matrix
 * @return {void} Do not return anything, modify matrix in-place instead.
 */
// 矩阵变换
var rotate = function(matrix) {
    const length = matrix.length;
    for(let i = 0; i < matrix.length/2; i++) {
        // 后面为什么会减1 , 不是因为Length - 1, 而是因为slice 不包括第二个间隔值
        const axis = matrix[i].slice(i, matrix[i].length - 1 - i); // 这里有一个浅拷贝
        for (let j = 0; j < axis.length; j++) {
            // axis[j] === matrix[i][i + j]; // i = 1, j = 0 时：(i, i+j), (1，1) 3
            // 旋转90度: （i + j, length - 1 - i）, (1, 2) 4
            if (length - i - 1 === i + j && i === i + j) {
                break; // 同一个点，结束轮询
            }
            // console.log(matrix[i][i + j], matrix[i+j][length - 1 -i], matrix[length - 1 - i][length - 1 - i - j], matrix[length - 1 - i - j][i]);
            let temp = matrix[i+j][length - 1 -i];
            matrix[i+j][length - 1 - i] = axis[j];
            axis[j] = temp;
            // 旋转180度: （length - 1 - i, length - 1 - i - j）, (2, 2) 8;
            temp = matrix[length - 1 - i][length - 1 - i - j];
            matrix[length - 1 - i][length - 1 - i - j] = axis[j];
            axis[j] = temp;
            // 旋转270度: （length - 1 - i - j, length - 1 - i + j）, (2, 1);
            temp = matrix[length - 1 - i - j][i];
            matrix[length - 1 - i - j][i] = axis[j];
            // 归0
            matrix[i][i + j] = temp;
            // console.log(temp, matrix[i][i + j], matrix[i+j][length - 1 -i], matrix[length - 1 - i][length - 1 - i - j], matrix[length - 1 - i - j][i]);

        }
        // if (axis.length === 1) {
        //     break;
        // }
    }
};
```