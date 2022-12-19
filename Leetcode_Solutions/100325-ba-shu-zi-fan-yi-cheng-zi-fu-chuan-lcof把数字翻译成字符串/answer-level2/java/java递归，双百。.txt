```
class Solution {
    var count = 0
    fun translateNum(num: Int): Int {

        dfs(num.toString(), 0, 0)
        dfs(num.toString(), 0, 1)
        
        return count
    }

    private fun dfs(num: String, start: Int, end: Int) {
        if (start >= num.length || end >= num.length) {
            return
        }

        if (start != end && (num.substring(start, end + 1).toInt() >= 26 || 
                num[start] == '0')) {
            return
        }
        if (end + 1 == num.length) {
            count ++
            return
        }
        dfs(num, end + 1, end + 1)
        dfs(num, end + 1, end + 2)
    }
}
```
