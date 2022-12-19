```
object Solution {
    def dfs(s:String):Boolean = {
      println(s)
      var start = 0 
      var end = s.length - 1
      while(start < end){
        if(s(start) != s(end)) return false
        start += 1
        end -= 1
      }
      return true
    }
    def validPalindrome(s: String): Boolean = {
      if(s.length <= 2) return true
      var start = 0 
      var end = s.length - 1
      while(start<end){
        if(s(start)==s(end)){
          start += 1
          end -= 1
        }else{
          return dfs(s.slice(start + 1, end + 1)) || dfs(s.slice(start, end))
        }
      }
      return true
    }
}
```
