### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[][]} A
 * @return {number[][]}
 */
var transpose = function(A) {
    let n = A.length
    let m = A[0].length
    // 创建个空的 m*n 二维数组
    let list = Array.apply(null,Array(m)).map(item => {
      return Array.apply(null,Array(n)).map(item => {
        return ''
      })
    })
    // 循环对调
    for(let i=0;i<m;i++){
      for(let j=0;j<n;j++){
        list[i][j] = A[j][i]
      }
    }
    return list
};
```