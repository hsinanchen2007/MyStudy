```
object Solution {
  def nextGreatestLetter(letters: Array[Char], target: Char): Char = {

    var left = 0
    var right = letters.length - 1

    while (left < right) {
      val mid = (left + right) >> 1
      if (letters(mid) > target) {
        if (mid == 0) return letters(mid)
        else if (letters(mid - 1) <= target) return letters(mid)
        else {
          right = mid - 1
        }
      } else {
        left = mid + 1
      }
    }
    if (letters(left) > target) letters(left) else letters(0)
  }
}

```
