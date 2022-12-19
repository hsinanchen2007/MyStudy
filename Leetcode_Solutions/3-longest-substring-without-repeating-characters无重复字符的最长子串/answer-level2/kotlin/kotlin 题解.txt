执行用时 : 272 ms , 在所有 Kotlin 提交中击败了 100.00% 的用户
内存消耗 : 35.7 MB , 在所有 Kotlin 提交中击败了 71.11% 的用户
# 思路：
1. 滑动窗口
2. 查表

# 代码：
```
class Solution {
  fun lengthOfLongestSubstring(s: String): Int {
    if (s == "") return 0
    var h = 0
    var t = 0
    val arr = IntArray(256) { -1 }
    var maxLength = 0
    while (t < s.length) {
      val char = s[t]
      val charIdx = arr[s[t].toInt()]
      if (charIdx > h) {
        h = charIdx + 1
      } else if (charIdx == h) {
        h++
      }
      if (t - h + 1 > maxLength) {
        maxLength = t - h + 1
      }
      arr[char.toInt()] = t
      t++
    }
    return maxLength
  }
}
```
