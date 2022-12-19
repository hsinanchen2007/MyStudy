```
fun romanToInt(s: String): Int {
        var res :Int = getNum(s[s.length - 1])
        for (i in s.length-2 downTo 0){
           res += if (getNum(s[i]) < getNum(s[i + 1])) -getNum(s[i])  else    getNum(s[i])
        }
        return res
    }
    fun getNum(c:Char) = when(c){
        'I' -> 1
        'V' -> 5
        'X' -> 10
        'L' -> 50
        'C' -> 100
        'D' -> 500
        'M' -> 1000
        else -> 0
    }
```
