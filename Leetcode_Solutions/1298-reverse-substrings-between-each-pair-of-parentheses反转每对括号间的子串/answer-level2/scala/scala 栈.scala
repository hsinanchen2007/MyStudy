```scala
object Solution {
  def reverseParentheses(s: String): String = {
    var str = ""
    val st = new mutable.Stack[Char]
    s.foreach(i => {
      if (i == ')') {
        while (st.top != '(') {
          str += st.top
          st.pop
        }
        st.pop
        str.foreach(j => st.push(j))
        str = ""
      } else st.push(i)
    })
    while (st.nonEmpty) {
      str += st.top
      st.pop
    }
    str.reverse
  }
}
```
