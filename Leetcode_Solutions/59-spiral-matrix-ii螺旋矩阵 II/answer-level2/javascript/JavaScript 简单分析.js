// ![859B87259222E52A313A188F9BF3688B.jpg](https://pic.leetcode-cn.com/7a200db5e07e2e461f801efa01c72096cc3fe58ccb22f7e3cdd44398cb16f61a-859B87259222E52A313A188F9BF3688B.jpg)

// 模拟一下过程即可，其实和高赞差不多

// n=3 时

// [走 3 步，向右，起始点为`(0, -1)`(上一步的终点)]
// [走 2 步，向下，起始点为`(0, 3)`(上一步的终点)]
// [走 2 步，向左，起始点为`(3, 3)`(上一步的终点)]
// [走 1 步，向上，起始点为上一步的终点]
// [走 1 步，向右，起始点为上一步的终点]

// n = 4 时

// 步长数组：

// `[4,3,3,2,2,1,1]`

// 代码如下

// ```javascript []
/**
 * @param {number} n
 * @return {number[][]}
 */
var generateMatrix = function(n) {

  // 根据 n 构建步长数组

  /** 每一步的步长 */
  var steps = []
  var step = n
  while (step > 0) {
    if (step === n) {
      steps.push(step)
    } else {
      steps.push(step)
      steps.push(step)
    }
    step--
  }

  // 生成空矩阵

  var resultMatrix = []
  for (var i = 0; i < n; i++) {
    resultMatrix.push([])
  }
  // console.log({ resultMatrix, steps })

  // 遍历步长数组，改变目标坐标并赋值

  var currentPoint = [0, -1]
  /** 节点值 */
  var value = 0
  for (var i = 0; i < steps.length; i++) {
    /** 步长 */
    var S = steps[i]
    /** 角 */
    var P = i % 4
    // 0 左上角开始》向右改变横坐标
    // 1 右上角开始》向下改变纵坐标
    // 2 右下角开始》向左改变横坐标
    // 3 右上角开始》向上改变纵坐标
    for (var j = 0; j < S; j++) {
      value++
      switch (P) {
        case 0:
          currentPoint[1] = currentPoint[1] + 1
          break
        case 1:
          currentPoint[0] = currentPoint[0] + 1
          break
        case 2:
          currentPoint[1] = currentPoint[1] - 1
          break
        case 3:
          currentPoint[0] = currentPoint[0] - 1
          break
      }
      resultMatrix[currentPoint[0]][currentPoint[1]] = value
    }
  }
  return resultMatrix
}
// ```

// > leetcode 啥时候支持 Typescript 啊🤪