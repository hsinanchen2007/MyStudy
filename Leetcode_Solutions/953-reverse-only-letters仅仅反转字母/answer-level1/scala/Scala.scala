### 解题思路
此处撰写解题思路

### 代码

```scala
object Solution {
    def reverseOnlyLetters(S: String): String = {
        import java.util
     val letters = new util.Stack[Character]()
    val res = new StringBuilder()
    S.toCharArray
      .foreach(c => if (Character.isLetter(c)) letters.push(c))
   
    S.toCharArray
      .foreach(c => if (Character.isLetter(c)) res.append(letters.pop())
      else res.append(c))
    res.toString   
    }
}
```