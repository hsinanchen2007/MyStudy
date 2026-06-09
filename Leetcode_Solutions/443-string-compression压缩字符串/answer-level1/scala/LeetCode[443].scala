```
  def compress(chars: Array[Char]): Int = {
    if (chars.size == 1) return 1
    var prev = chars(0)
    var num = 1
    var j = 1
    for (i <- 1 to chars.size - 1) {
      if (chars(i) == prev) {
        println(chars(i))
        num += 1
        println(num)
      } else {
        if (num > 1) {
          for (elem <- num.toString.toArray) {
            chars(j) = elem
            j += 1
          }
        }
        num = 1
        chars(j) = chars(i)
        j += 1
        prev = chars(i)
      }
    }
    if (num > 1) {
      for (elem <- num.toString.toArray) {
        chars(j) = elem
        j += 1
      }
    }
    j
  }
```
