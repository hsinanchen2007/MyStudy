 * 使用Set保存当前窗口内的所有字符，用于判定下一个字条是否已经存在；
 * 使用一个Array，保存窗口内所有字符在原字符串中的下标；
 * 从头到尾遍历整个字符串，同时更新窗口信息，分两大步：
 *  1. 如果下个字符不在窗口内，则添加之，使窗口加1
 *  2. 如果下个字符在窗口内，则先记录当前窗口，然后收缩窗口，剔除indexInWindow中记录的已存在字符下标之前的所有字符

```scala []
object Solution {
  def lengthOfLongestSubstring(s: String): Int = {
      if (s == null || s == None || s.length() == 0) return 0
      var words = scala.collection.mutable.Set[Char]()
      val chars = s.toCharArray
      var start = 0
      var window = 0
      var result = window
      val indexInWindow = new Array[Int](256)
      while(start + window < s.length()) {
        val loc = start + window
        val curChar = chars(start + window)
        if (words.contains(curChar)) {
            val lastLoc = indexInWindow(curChar)
            for (i <- start to lastLoc) {
                words -= chars(i)
            }
            result = if (window > result) window else result
            
            window -= lastLoc - start + 1
            start = lastLoc + 1
        } else {
            window += 1
            words += curChar
            indexInWindow(curChar) = loc
        }
      }
      if (window > result) window else result
  }
}
```