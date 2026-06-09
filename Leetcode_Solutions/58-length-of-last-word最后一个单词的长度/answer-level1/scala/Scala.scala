object Solution {
    def lengthOfLastWord(s: String): Int = {
        var end = s.length() - 1
    while (end >= 0 && s.charAt(end) == ' ')
      end -= 1
    if (end < 0) return 0
    var start = end
    while (start >= 0 && s.charAt(start) != ' ')
      start -= 1
    end - start
    }
}