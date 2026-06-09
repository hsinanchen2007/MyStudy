### 解题思路
此处撰写解题思路

### 代码

```scala
object Solution {
    def removeOuterParentheses(S: String): String = {
      val s = new StringBuilder
    var level = 0
    for (c <- S.toCharArray) {
      if (c == ')') level -= 1
      if (level >= 1) s.append(c)
      if (c == '(') level += 1
    }
    s.toString  
    }
}
```