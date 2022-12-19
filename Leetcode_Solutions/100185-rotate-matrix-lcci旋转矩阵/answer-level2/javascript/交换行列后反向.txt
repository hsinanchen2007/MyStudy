### 解题思路
先想的是复制数组，行列对换再反向，但是有额外空间，后来一想，直接数组内交换就行了
结果出来两个效率差不多，内存都是击败100%，后来的内存小了 0.1 M..

### 代码

复制数组
```javascript
var rotate = function(matrix) {
    const matrix2 = matrix.map(key=>[...key])
    const len = matrix.length
    for(let i=0;i<len;i++){
        for(let j=0;j<len;j++){
            matrix[j][i] = matrix2[i][j]
        }
    }
    matrix.forEach(item=>item.reverse())
};

```

数组内直接交换
```javascript
var rotate = function(matrix) {
    const len = matrix.length
    for(let i=0;i<len;i++){
        for(let j=i;j<len;j++){
            [matrix[j][i],matrix[i][j]] = [matrix[i][j],matrix[j][i]]
        }
    }
    matrix.forEach(arr=>arr.reverse())
};
```