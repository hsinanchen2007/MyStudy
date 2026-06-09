### 解题思路
此处撰写解题思路

### 代码

```scala
object Solution {
    def nextGreatestLetter(letters: Array[Char], target: Char): Char = {
        val l = letters.length
    for (i <- 0 until l) {
      if (letters(i) > target)
        return letters(i)
    }
    letters(0)
    }
}
```