### 解题思路

题目这么长,看起来很吓人, 还好, 起码不是描述不清, 简单的说就是 **下一步 车 能吃的 卒 有多少个**

车 是 纵来横去的 能吃的 只能在 车的 x y 轴 两个方向

所以, 

1. 只需 拿到两个数组: **横的数组** 和 **竖的数组**
2. **去除**无关的**小点**
3. 判断 车 的 **上一个** 或者 **下一个** 是不是 p, 是就加 1

``` js
//如: 
board = [
          [".",".",".",".",".",".",".","."],
          [".",".",".","p",".",".",".","."],
          [".",".",".","p",".",".",".","."],
          ["p","p",".","R",".","p","B","."],
          [".",".",".",".",".",".",".","."],
          [".",".",".","B",".",".",".","."],
          [".",".",".","p",".",".",".","."],
          [".",".",".",".",".",".",".","."]
        ]

// 筛选之后: xlist = ["p", "p", "R", "p", "B"]  ylist = ["p", "p", "R", "B", "p"]

// 这样是不是看起来是不是简单多了, 继续!
 
 // 我们只要看 R 的前一项和后一项: xlist = ["p", "R", "p"],  ylist=["p", "R", "B"]

// 这样看, 是不是有好看了不少, 嘿嘿, 尽得gui谷真传!
```

![image.png](https://pic.leetcode-cn.com/52a53bb6033a0c1dbd7ff397199c7fa5c584dbebfa2da183656e7df46c54d201-image.png)

### 代码

```javascript
/**
 * @param {character[][]} board
 * @return {number}
 */
var numRookCaptures = function(board) {
    let y, xlist = [], ylist = []

    board.forEach((item,index) => {
      if(item.indexOf('R') > -1) {
        y = item.indexOf('R')
        xlist = item.filter(t => t !== '.')
      }
    })

    board.forEach(item =>{
      item[y] !=='.' && ylist.push(item[y])
    })

    let Rx = xlist.indexOf('R'), Ry = ylist.indexOf('R'), num = 0

    if(xlist[Rx+1] && xlist[Rx+1] === 'p') ++num
    if(xlist[Rx-1] && xlist[Rx-1] === 'p') ++num
    if(ylist[Ry+1] && ylist[Ry+1] === 'p') ++num
    if(ylist[Ry-1] && ylist[Ry-1] === 'p') ++num

    return num

};
```