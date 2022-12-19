```scala
object Solution {
  def nextGreatestLetter(letters: Array[Char], target: Char): Char = {
    letters.filter(_ > target).sorted.headOption.getOrElse(letters.min)
  }
}
```
