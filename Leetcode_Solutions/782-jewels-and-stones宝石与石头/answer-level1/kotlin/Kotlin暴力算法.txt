```
fun numJewelsInStones(J: String, S: String): Int {
    var count:Int = 0
    for (i in J) {
        for (m in S) {
            if(i==m) {
                count+=1
            }
        }
    }
    return count
}
```
暴力双层for循环
