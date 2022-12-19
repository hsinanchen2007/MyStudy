此办法虽然很愚笨，但也是一种新的解题思路。效率应该还可以优化
思路看清题目超出int范围的都将其捕获然后输出0，输入x转为倒叙插入到数据列表里面，然后将其转为long类型判断其是否超int类型，超出则输出0，不超出则返回正常结果。
```
fun reverse(x: Int): Int {
        var list = mutableListOf<Char>()
        var char: String
        var newChar = ""
        var isMinus = false
        if (x >= 0) {
            char = x.toString()
            isMinus = false
        } else {
            char = x.toString().split("-")[1]
            isMinus = true
        }
        for (m in char) {
            list.add(0, m)
        }
        System.out.println("====>" + list.toString())
        for (c in list) {
            newChar += c
        }
        var long: Long = 0
        if (isMinus) {
            long = -newChar.toLong()
        } else {
            long = newChar.toLong()
        }
        if (long > Int.MAX_VALUE || long < Int.MIN_VALUE) {
            return 0
        }
        return long.toInt()
    }
```