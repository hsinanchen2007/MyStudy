### 解题思路
遍历moves字符串进行模式匹配

### 代码

```scala
object Solution {
    def judgeCircle(moves: String): Boolean = {
    var x = 0
    var y = 0
    for (i <- 0 until moves.length) {
      moves(i) match {
        case 'U' => y += 1
        case 'D' => y -= 1
        case 'L' => x -= 1
        case 'R' => x += 1
      }
    }
    if (x == 0 && y == 0) return true
    false    
    }
}
```