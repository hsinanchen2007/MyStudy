### 解题思路
![微信截图_20200407132953.png](https://pic.leetcode-cn.com/228dcf216db62dd82947c224625457534076d499e9a5aeec240d85a0a93ebb69-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20200407132953.png)

![微信截图_20200407131956.png](https://pic.leetcode-cn.com/10002039b3461094c5120882b94708d1de38d7c210e449ba3c8447d9589dee68-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20200407131956.png)

注：其他翻转思路类似

### 代码

```javascript
/**
 * @param {number[][]} matrix
 * @return {void} Do not return anything, modify matrix in-place instead.
 */
var rotate = function(matrix) {
    let len=matrix.length,
        lenChild=matrix[0].length;
    // 斜对角翻转
    for (let i=0;i<len-1;i++){
        for (let j=i+1;j<len;j++){
            // 元素交换
            let tmp=matrix[i][j];
            matrix[i][j]=matrix[j][i];
            matrix[j][i]=tmp;
        }
    }
    // 水平翻转
    for (let i=0;i<len;i++){
        for (let j=0;j<lenChild/2;j++){
            // 元素交换
            let tmp=matrix[i][j];
            matrix[i][j]=matrix[i][lenChild-j-1];
            matrix[i][lenChild-j-1]=tmp;
        }
    }
};
```