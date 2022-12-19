#### 解题思路
&emsp;&emsp; 标准的DFS题目，根据题意值都大于等于0，4个方向遍历打标记就行，注意处理数组的边界问题。最后将标记的值替换成目标值即可。
#### 代码
```javascript []
var floodFill = function(image, sr, sc, newColor) {
    function dfs(image, x, y, target){
        if(image[x][y] < 0) return;
        if(image[x][y] == target){
            image[x][y] = -1;
            x - 1 >= 0 && dfs(image, x - 1, y, target)
            x + 1 <= image.length - 1 && dfs(image, x + 1, y, target)
            dfs(image, x, y - 1, target);
            dfs(image, x, y + 1, target);
        }
    }
    dfs(image, sr, sc, image[sr][sc]);
    for(let i = 0; i < image.length; i++){
        for(let j = 0; j < image[i].length; j++){
            if(image[i][j] < 0){
                image[i][j] = newColor;
            }
        }
    }
    return image;
};
```
