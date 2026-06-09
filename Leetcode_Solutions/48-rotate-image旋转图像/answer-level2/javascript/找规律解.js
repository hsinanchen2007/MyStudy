### 解题思路
![image.png](https://pic.leetcode-cn.com/6b6f04f347c57b76791974ab877c74d83acc1f971f342068ef344a5ff7c33e19-image.png)


找规律
//[0,0] --> [0,3]
//[1,0] --> [0,2]
//[1,1] --> [1,2]?
//[2,1] --> [1,1]?
//[3,2] --> [2,0]
//[2,2] --> [2,1]?
//[y,x] --> [x,length-(x+1)]

重新放位置

完事
### 代码

```javascript
/**
 * @param {number[][]} matrix
 * @return {void} Do not return anything, modify matrix in-place instead.
 */
var rotate = function(matrix) {
   //[0,0] --> [0,3]
   //[1,0] --> [0,2]
   //[1,1] --> [1,2]?
   //[2,1] --> [1,1]?
   //[3,2] --> [2,0]
   //[2,2] --> [2,1]?
    //[y,x] --> [x,length-(x+1)]
    let yLen = matrix.length
    let xLen = matrix[0].length
    let arr = JSON.parse(JSON.stringify(matrix))
    for(let y=0;y<yLen;y++){
        for(let x = 0;x<xLen;x++){
            matrix[x][xLen-(y+1)] = arr[y][x]
        }
    }
};
```