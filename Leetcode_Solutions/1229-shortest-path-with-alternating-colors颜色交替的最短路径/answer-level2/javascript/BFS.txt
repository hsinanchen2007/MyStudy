- 表示到达i节点时 最后一个路径为红色路径  目前保存的最小长度
- 表示到达i节点时 最后一个路径为蓝色路径  目前保存的最小长度
- redArr[i][j] blueArr[i][j] = 1 邻接矩阵 表示 i指向j的有向边
- redPoints bluePoints表示遍历的起始点  默认都是[0]
- 题目要求边的颜色交替
- 例如 redPoints[i] = startPoint 需要在blueArr[startPoint]中找蓝色的有向边 终点为endPoint 同时更新 blue
- blue = Math.min(red[startPoint] + 1, blue[endPoint]) 并将找到的蓝色endPoint 加入到下一轮的tempBluePoints中
```
var shortestAlternatingPaths = function (n, red_edges, blue_edges) {
  let red = new Array(n).fill(1000)
  let blue = new Array(n).fill(1000)
  red[0] = 0
  blue[0] = 0
  let redArr = Array.from({ length: n }, () => new Array(n).fill(0))
  let blueArr = Array.from({ length: n }, () => new Array(n).fill(0))
  red_edges.forEach(([y, x]) => redArr[y][x] = 1)
  blue_edges.forEach(([y, x]) => blueArr[y][x] = 1)
  let redPoints = [0];
  let bluePoints = [0];
  while (redPoints.length || bluePoints.length) {
    let tempBluePoints = []
    let tempRedPoints = []
    if (redPoints.length) {
      redPoints.forEach(point => {
        blueArr[point].forEach((el, target) => {
          if (el && blue[target] > red[point] + 1) {
            blue[target] = red[point] + 1
            tempBluePoints.push(target)
          }
        })
      })
    }
    if (bluePoints.length) {
      bluePoints.forEach(point => {
        redArr[point].forEach((el, target) => {
          if (el && red[target] > blue[point] + 1) {
            red[target] = blue[point] + 1
            tempRedPoints.push(target)
          }
        })
      })
    }
    redPoints = tempRedPoints
    bluePoints = tempBluePoints
  }
  return blue.map((el, i) => {
    let res = Math.min(el, red[i]);
    return res <= 999 ? res : -1
  })
}
```
