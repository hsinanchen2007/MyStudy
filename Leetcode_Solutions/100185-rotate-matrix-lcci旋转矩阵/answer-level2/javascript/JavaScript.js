### 解题思路
![image.png](https://pic.leetcode-cn.com/628c3bda115cbad2980d8963c3eeed96777a2652c87798339190c021a7681412-image.png)

- 通过 ES6 解构赋值进行转置
- 然后 reverse（） 倒叙

### 代码

```javascript
/**
 * @param {number[][]} matrix
 * @return {void} Do not return anything, modify matrix in-place instead.
 */
var rotate = function(matrix) {
    let r = matrix.length
    let c = matrix[0].length
    for(let i = 0; i < c; i++){
        for (let j = i; j < c; j++){
            [matrix[i][j],matrix[j][i]] = [matrix[j][i],matrix[i][j]]
        }
    }
     matrix.forEach( x => x.reverse())
};
```