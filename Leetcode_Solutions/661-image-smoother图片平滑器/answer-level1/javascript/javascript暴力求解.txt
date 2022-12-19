### 解题思路
* 需要注意的一点,JS中创建二维数组比较麻烦；

### 代码

```javascript
/**
 * @param {number[][]} M
 * @return {number[][]}
 */
var imageSmoother = function(M) {
 let R = M.length
 let C = M[0].length
 let ans = []
 for( let i = 0; i < R; i++){
     for( let j = 0; j < C; j++){
         //创建二维数组
         if(!Array.isArray(ans[i])){
             ans[i] = []
         }
        // 添加本身的值
         let sum = M[i][j]
         let num = 1
        //判断8个方向的是否有值，是否可以添加sum中
        if(i > 0 && j > 0)
            {sum += M[i-1][j-1]; num++;};
        if(i > 0)
            {sum += M[i-1][j]; num++;};
        if(i > 0 && j < C -1)
            {sum += M[i -1][j + 1]; num++;};
        if(j > 0)
            {sum += M[i][j - 1]; num++;};

        if(j < C - 1)
            {sum += M[i][j + 1]; num ++;};

        if(i < R - 1)
            {sum += M[i + 1][j]; num++;};

        if(i < R - 1 && j > 0)
            {sum += M[i + 1][j - 1]; num++;};

        if(i < R - 1 && j < C - 1)
            {sum += M[i + 1][j + 1]; num++;};
        //最后通过Math.floor向下取整；
        ans[i][j] = Math.floor(sum / num)
     }
 }
    return ans
    
};
```