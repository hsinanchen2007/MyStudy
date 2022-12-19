* 首先判断该数是否为0
* 其次判断根据取模操作判断每一位数是否满足条件 `x != 0 && num/x == 0`
```
fun selfDividingNumbers(left: Int, right: Int): List<Int> {
    fun isSelfDividingNumber(num: Int): Boolean {
        if (num == 0) return false
        var t = num
        while (t / 10 > 0) {
            val x = t % 10
            if (x == 0 || num % x != 0) return false
            t /= 10
            if(t < 10){
                return num % t == 0
            }
        }
        return true
    }

    val list = mutableListOf<Int>()
    if (right < left) return listOf()
    for (i in left..right) {
        if (isSelfDividingNumber(i)) {
            list.add(i)
        }
    }
    return list
}
```
