```scala
object Solution {
  def numberToWords(num: Int): String = {
    var n = num
    var res = func(n % 1000)
    val arr = Array("Thousand", "Million", "Billion")
    (0 until 3).foreach(i => {
      n /= 1000
      res = if (n % 1000 != 0) func(n % 1000) + " " + arr(i) + " " + res else res
    })
    res = res.replaceAll("\\s+$", "")
    if (res.isEmpty) "Zero" else res
  }

  def func(num: Int): String = {
    val v1 = Array("", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen")
    val v2 = Array("", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety")
    var res = ""
    val a = num / 100
    val b = num % 100
    val c = num % 10
    res = if (b < 20) v1(b) else v2(b / 10) + (if (c > 0) " " + v1(c) else "")
    if (a > 0) res = v1(a) + " Hundred" + (if (b > 0) " " + res else "")
    res
  }
}
```
