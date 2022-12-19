```java

class SolutionKt {

    fun balancedStringSplit(s: String): Int {
        var result = 0
        var num = 0

        s.forEachIndexed { _, c ->
            if (c == 'L') {
                num++
            } else {
                num--
            }
            if (num == 0) {
                result++
            }
        }
        return result
    }
}

```