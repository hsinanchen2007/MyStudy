```
object Solution {
  def letterCasePermutation(S: String): List[String] = {
    if (S.length == 0) return List("")
    val strings: List[String] = letterCasePermutation(S.slice(1, S.length))
    if (S(0).isLetter) strings.flatMap(x => List(S(0).toLower + x, S(0).toUpper + x))
    else strings.map(x => S(0) + x)
  }
}
```
