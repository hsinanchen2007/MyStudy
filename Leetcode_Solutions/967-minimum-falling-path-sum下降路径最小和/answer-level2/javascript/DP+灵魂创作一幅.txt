不拐弯抹角的DP，灵魂创作一幅：
![IMG_8B4B7FF5E7A2-1.jpeg](https://pic.leetcode-cn.com/44f777fa7afa47444aa1e995ed96706af2d3d4c0053fa02298a95d13e04aa4ea-IMG_8B4B7FF5E7A2-1.jpeg)

```js
/**
 * @param {number[][]} A
 * @return {number}
 */
var minFallingPathSum = function(A) {
    // 虽然题目说了不存在这种情况
    // 但是出于习惯
    // 还是做了防御性编程
    let rows = A.length
    if(!rows) return 0
    let cols = A[0].length
    if(!cols) return 0

    // 第1⃣️层循环同于行的迭代
    // 第2⃣️层循环同于列的迭代
    for(let i = 1; i < rows; i++) {
        for(let j = 0; j < cols; j++) {
            // 以下逻辑见“灵魂创作”
            if(j === 0) {
                A[i][j] = Math.min(A[i - 1][j], A[i - 1][j + 1]) + A[i][j]
            } else if(j === cols - 1) {
                A[i][j] = Math.min(A[i - 1][j - 1], A[i - 1][j]) + A[i][j]
            } else {
                A[i][j] = Math.min(A[i - 1][j - 1], A[i - 1][j], A[i - 1][j + 1]) + A[i][j]
            }
        }
    }
    return Math.min(...A[rows - 1])
};
```
我这里在空间上是直接复用了`A`, 本来应该新建一个`dp`数组, 但是为了空间复杂度...
