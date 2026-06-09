object Solution {
    def isValid(s: String): Boolean = {
    if (s.length % 2 != 0) return false
    var a = s
    while (a.contains("{}") || a.contains("[]") || a.contains("()")) {

      if (a.contains("{}")) a = a.replace("{}", "")
      if (a.contains("()")) a = a.replace("()", "")
      if (a.contains("[]")) a = a.replace("[]", "")
    }
    a.isEmpty
    }
}