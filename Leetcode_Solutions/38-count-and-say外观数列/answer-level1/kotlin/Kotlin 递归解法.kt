# 思路
首先需要理解题目并 Get 到题目的点。这道题理解后发现，求 n 的报数，其实就是求对 n - 1 报数的描述。因此我们可以使用递归，先求出 n - 1 的结果，然后再对这个报数进行描述即可。

既然是递归，那么肯定会有结束条件。结束条件就是 n = 1，因为当 n = 1 时，此时没有上一个数了，因此 n = 1 时直接返回 “1” 即可。

主要的难点在于如何描述上个报数上，我们可以先将上个报数转成字符数组，然后利用计数器，依次获取每个数字出现的次数。

首先，取第一个报数的字符进行初始判断，然后往后依次判断是否相等，相等则计数 + 1，不相等则进行计数和数的拼接。

这里有一点需要注意的时，为了方便代码的处理，可以将上一个报数的后面追加一个与数字无关的字符，避免漏掉拼接的问题。


# 代码
```
class Solution {
  // 加入哈希表，避免递归过程中的重复计算
  private val map = HashMap<Int, String>()

  fun countAndSay(n: Int): String {
    if (n == 1) return "1"

    // 如果有保存好的结果则直接返回
    if (map.contains(n)) {
      return map[n] as String
    }

    // 计算出上一个数的报数
    val prevSay = countAndSay(n - 1)

    // 当前数的报数就是对上一个数的描述
    val sb = StringBuilder()
    val chs = "$prevSay#".toCharArray() // 对上个数的报数追加一个与数字无关的符号，方便后续代码的处理
    var prev = chs[0] // 取第一个字符作为初始判断
    var count = 1 // 记录每个数字出现的次数，默认为 1
    for (i in 1 until chs.size) {
      val ch = chs[i]
      if (ch == prev) {
        count ++ // 计数 + 1
      } else {
        sb.append("$count$prev") // 拼接
        prev = ch
        count = 1
      }
    }

    val ans = sb.toString()
    map[n] = ans
    return ans
  }
}
```
