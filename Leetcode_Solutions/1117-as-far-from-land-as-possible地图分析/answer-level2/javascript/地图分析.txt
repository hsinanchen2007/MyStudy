```
/**地图分析
 * @param {number[][]} grid
 * @return {number}
 */
var maxDistance = function(grid) {
    var land = [];
    var ocean = [];
    //记录 陆地和海洋
    for (var i = 0;i < grid.length;i++) {
        for (var j = 0;j < grid.length;j++) {
            if (grid[i][j]) {
                land.push([i, j]);
            }else {
                ocean.push([i, j]);
            }
        }
    }
    if (land.length == 0||ocean.length == 0) {
        return -1;//没有海洋或没有陆地
    }
    //求每一个海洋区域跟所有陆地的最小距离，
    //然后在所有最小距离中求最大距离，就是所有海洋离陆地最远的距离
    var max = -1;
    for (var i = 0;i < ocean.length;i++) {
        //求一片海洋到所有陆地的距离中最小的距离
        var min = 9999999;
        for (var j = 0;j < land.length;j++) {
            var dis = distance(ocean[i], land[j]);
            if (dis < min) {
                min = dis;
            }
            if (min == 1) {
                break;//提前结束，最小可能的距离是1
            }
        }
        //求最小距离中的最大距离
        if (min > max) {
            max = min;
        }
    }
    return max;
};

/**
 * 曼哈顿距离
 * @param a
 * @param b
 * @returns {number}
 */
function distance(a, b) {
    return Math.abs(a[0] - b[0]) + Math.abs(a[1] - b[1]);
}

```
