```
object Solution {
    def isPalindrome(x: Int): Boolean = {
        val str = x.toString
        var left = 0
        var right = str.length()-1
        while(left<=right) {
            if(str.charAt(left) == str.charAt(right)) {
                left = left + 1
                right = right - 1
            }
            else {
                return false
            }
        }
        return true
    }
}
```
