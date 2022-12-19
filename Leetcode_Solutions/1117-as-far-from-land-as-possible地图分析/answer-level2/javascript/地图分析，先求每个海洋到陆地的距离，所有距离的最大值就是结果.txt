![TIM图片20190905102439.png](https://pic.leetcode-cn.com/9c3ce4d00820963c26a99f2140ad406a4e15a39c386a0e61a33ff4d12a481fdd-TIM%E5%9B%BE%E7%89%8720190905102439.png)

**1.一个海洋区域距离陆地有多远，由最近的陆地决定。**<br>
**2.一个海洋区域和陆地的距离，定义为这个海洋区域和所有陆地区域的距离的最小值。**<br>
**3.每一个海洋区域和陆地的距离中最大，就是用距离陆地最远的海洋区域。**<br>
**4.效率可能是低了一点，不过可以提供一种参考也是好的。**<br>
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

