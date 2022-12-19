### 解题思路
![image.png](https://pic.leetcode-cn.com/f1a919a983315352090d381da8d61be62145099cb29235bc3918ca06a69da053-image.png)

和《岛面积》，《岛数量》几个题类似，用队列，需要注意如果newColor和指定位置的原来的color一样，就没必要继续下去了，直接return即可。


### 代码

```javascript
/**
 * @param {number[][]} image
 * @param {number} sr
 * @param {number} sc
 * @param {number} newColor
 * @return {number[][]}
 */
var floodFill = function (image, sr, sc, newColor) {
    if (!image.length || !image[0].length) return image;
    if (image[sr][sc] === newColor) return image;
    const oldColor = image[sr][sc];
    const height = image.length;
    const width = image[0].length;
    let que = [[sr, sc]]; // store the coordinates
    image[sr][sc] = newColor;

    while (que.length) {
        let len = que.length;
        for (let i = 0; i < len; i++) {
            const pos = que.shift();
            const x = pos[0];
            const y = pos[1];
            if (x > 0 && image[x - 1][y] === oldColor) {
                que.push([x - 1, y]);
                image[x - 1][y] = newColor;
            }
            if (x < height - 1 && image[x + 1][y] === oldColor) {
                que.push([x + 1, y]);
                image[x + 1][y] = newColor;
            }
            if (y > 0 && image[x][y - 1] === oldColor) {
                que.push([x, y - 1]);
                image[x][y - 1] = newColor;
            }
            if (y < width - 1 && image[x][y + 1] === oldColor) {
                que.push([x, y + 1]);
                image[x][y + 1] = newColor;
            }
        }
    }
    return image;
};
```