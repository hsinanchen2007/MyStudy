### 解题思路
 1. 出发点
    考虑题目给出的条件,我们需要考虑最少需要的计算次数,才能保证不漏不重的检查完所有点.
    根据题目条件,遍历commands至少是O(m),而obstacles至少是O(n).
    由上可知,我们猜测最少需要的步骤为O(m+n).
    2. 条件挖掘
       1. 既然,我们要达到O(m+n),自然需要分别遍历commands和obstacles.
          1. 遍历commands只需要一遍,这是为了找到第一个周期的path
          2. 遍历obstacle则需要考虑,怎么裁剪搜索空间.
       2. 注意到条件说明,如果先到达且在此之前没有碰撞,则可视为成功.于是,我们考虑能否通过dest来缩小搜索域.注意符合条件的点的有如下特性:(obstacle.x <= dest.x && obstack.y <= dest.y)且path是有序的,那么可以遍历查找obstacle.如果,此时找到碰撞,则返回false,否则,返回上一步的是否可达标记.

### 代码

```javascript
/**
 * @param {string} command
 * @param {number[][]} obstacles
 * @param {number} x
 * @param {number} y
 * @return {boolean}
 */
var robot = function (command, obstacles, x, y) {
    // 预判为周期问题,则必须考虑先找一个周期内的规律
    // 由条件知,必须先将commands解析出来
    let path = []
    let origin = [0, 0]
    path.push[origin]
    let c = ''

    for (i = 0; i < command.length; i++) {
        c = command[i]
        if (c == "U") {
            origin[1] += 1
        } else {
            origin[0] += 1
        }
        path.push([origin[0], origin[1]])
    }
    let vec = path.pop()
    path.push(vec)
    let flag = checkPos([x, y], vec, path)

    if (!flag) {
        return false
    }

    let crashed = obstacles.filter((val) => val[0] <= x && val[1] <= y).find(obstacle => checkPos(obstacle, vec, path))

    if (flag && !crashed) {
        return true
    }
    return false
}
/**
 * @param {number[]} obstacle
 * @param {number[]} vec 
 * @param {number[][]} path
 */
function checkPos(obstacle, vec, path) {
    let scaleX = Math.ceil(obstacle[0] / vec[0]) - 1
    let scaleY = Math.ceil(obstacle[1] / vec[1]) - 1
    let scale = Math.max(scaleX, scaleY)
    obstacle[0] -= (scale * vec[0])
    obstacle[1] -= (scale * vec[1])
    if(path.find(pos => pos[0] == obstacle[0] && pos[1] == obstacle[1])){
        return true
    }
    
    return false
}
```