### 解题思路

看懂题目, 一开始看题目有点懵逼, 示例怎么一下子 [[2]] 一下子又 [[1,1,1],[1,0,1],[1,1,1]], 什么鬼的

然后, 示例2,结合这图看了一会,才发现怎么肥四!
![image.png](https://pic.leetcode-cn.com/7d576730d34c1a358102a080c7ac868c438e68bbd423e5644863745ba31c2c6e-image.png)

grid的长度 表示为 x , grid[i]的长度为 y, grid[i]中的每一个数值表示 有多少个 方块;

```
如:[[1,0],[0,2]]

下图分别是从x y z 三个方向看到的结果

```
![image.png](https://pic.leetcode-cn.com/3659a6e10876bb7dc8ae55b887f3029d23c5ba75f6817d51b05df8dc7d17b3ea-image.png)

由此, 我们可以看出

1. x 方向看到的面积为 grid 的每个子数组中 最大值总和
2. y 方向看到的面积为 grid[i] 每列中的最大值总和
3. z 方向看到的面积为 grid 每个子数组 除去0后的长度.
```
[
  [1,0],
  [0,2]
]

  x = 每行 [1,0] [0,2]的最大值 = [1] + [2] 值相加 = 3
  y = 每列 [1,0] [0,2]的最大值 = [1] + [2] 值相加 = 3 , 哈哈 咋一看和x一样, 只是纯属巧合
  z = 除去0后的长度 = [1] + [2] 的长度 = 2
 
 所以返回 x + y + z = 3 + 3 + 2 = 8
```

### 代码

```javascript
/**
 * @param {number[][]} grid
 * @return {number}
 */
var projectionArea = function(grid) {
    let x = y = z = 0
    grid.forEach((item,index) => {
      z += item.filter(t => t !==0).length
      x += Math.max(...item)
      let yM = 0
      grid.forEach(sub => {
        yM = Math.max(yM,sub[index])
      })
      y += yM
    })
    return x + y + z
};
```