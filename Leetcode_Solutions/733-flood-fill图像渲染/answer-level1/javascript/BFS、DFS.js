### 解题思路
方法一、DFS（递归）

### 代码

```javascript
/**
 * @param {number[][]} image
 * @param {number} sr
 * @param {number} sc
 * @param {number} newColor
 * @return {number[][]}
 */
var floodFill = function(image, sr, sc, newColor) {
    direction=[[0,1],[0,-1],[1,0],[-1,0]];
    if(image[sr][sc]!= newColor){
        var oldcolor = image[sr][sc];
        image[sr][sc] = newColor;
        for(var k=0;k<4;k++){
            var newx = sr+direction[k][0];
            var newy = sc+direction[k][1];
            if(newx>=0 && newx<image.length && newy>=0 && newy<image[0].length && image[newx][newy]==oldcolor){
                floodFill(image,newx,newy,newColor);
            }
        }
    }
    return image;
};
```
方法二、BFS
```
/**
 * @param {number[][]} image
 * @param {number} sr
 * @param {number} sc
 * @param {number} newColor
 * @return {number[][]}
 */
var floodFill = function(image, sr, sc, newColor) {
    if (image == null || image.length == 0 || image[0].length == 0 || image[sr][sc] == newColor) return image;
    var dir=[[0,1],[0,-1],[-1,0],[1,0]];
    var arr = [];
    var oldcolor=image[sr][sc];
    arr.push(sr * image[0].length + sc);
    while(arr.length>0){
        var str = arr.shift();
        var x=Math.floor(str/(image[0].length));
        var y=str%(image[0].length);
        image[x][y]=newColor;
        for(var k=0;k<4;k++){
            var newx=x+dir[k][0];
            var newy=y+dir[k][1];
            //这里的条件判断如果把image[newx][newy]==oldcolor放到前面就会报错，不知道为什么？
            if( newx>=0 && newx<image.length && newy>=0 && newy<(image[0].length) && image[newx][newy]==oldcolor )
            {
                arr.push(newx * (image[0].length) + newy);
            }
        }
    }
    return image;
};

```
