![image.png](https://pic.leetcode-cn.com/342865861a37a99dcc0630d4149d6c2a89e39f3b378142ea85e9678105b6b0b6-image.png)
循环一次路径数组,拿当前位置和下一个位置对比,因为不管是对角线或者按照网格线移动都是一秒,所以当他们相差的x轴和y轴数值 一致时, 所需时间就随便哪一个都行,反正这是x和y 数值一致, 然后不一致时就取大那个,这样就得到所需时间了
```
var minTimeToVisitAllPoints = function(points) {
    let num = 0
    for(let i = 0; i < points.length - 1; i++){
      let x = points[i][0]
      let y = points[i][1]
      let xn = points[i+1][0]
      let yn = points[i+1][1]
      let xc = Math.abs(xn - x)
      let yc = Math.abs(yn - y)
      if (xc - yc === 0 ) {
        num += xc
      } else if (xc - yc < 0) {
        num += yc
      } else if (xc - yc > 0) {
        num += xc
      }
    }
    return num
};
```
