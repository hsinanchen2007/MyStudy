object Solution {
    def strStr(haystack: String, needle: String): Int = {
    if (haystack.length < needle.length) return -1
    if (needle == "") return 0
    var i = 0
    var j = 0
    while (i < haystack.length && j < needle.length) {
      if (haystack(i) == needle(j)) {
        i += 1
        j += 1
      }
      else {
        i = i - j + 1
        j = 0
      }
      i
    }
    if (j == needle.length)
      return i - j
    -1
}
}