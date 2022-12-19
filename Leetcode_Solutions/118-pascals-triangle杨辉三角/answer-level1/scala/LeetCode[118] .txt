```
  def f(m: Int, n: Int): Int = {
    if (n == 1) return 1
    if (m == n) return 1
    return f(m - 1, n) + f(m - 1, n - 1)
  }

  def generate(numRows: Int): List[List[Int]] = {
    val inclusive = 1 to numRows
    inclusive.map( i => {
      (1 to i).map( j => f(i,j)).toList
    }).toList
  }
```
