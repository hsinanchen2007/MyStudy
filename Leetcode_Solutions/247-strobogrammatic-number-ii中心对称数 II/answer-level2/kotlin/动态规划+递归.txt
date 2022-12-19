两个100%!

执行用时 : 440 ms, 在所有 Kotlin 提交中击败了100.00%的用户
内存消耗 : 49 MB, 在所有 Kotlin 提交中击败了100.00%的用户

```
    val map1 = mapOf('0' to '0')
    val map2 = mapOf('1' to '1', '8' to '8')
    val map3 = mapOf('6' to '9', '9' to '6')

    fun findStrobogrammatic(n: Int): List<String> {
        val ans = mutableListOf<String>()
        findStrobogrammatic(n, "", "", ans, n)
        ans.sort()
        return ans
    }

    private fun findStrobogrammatic(n: Int, left: String, right: String, ans: MutableList<String>, max: Int) {
        if (n < 0) {
            //nothing
        } else if (n == 0) {
            ans.add("$left$right")
        } else if (n == 1) {
            map1.keys.forEach {
                ans.add("$left$it$right")
            }
            map2.keys.forEach {
                ans.add("$left$it$right")
            }
        } else {
            if (n != 2 && n != 3) {// in case of "01..." & "...10"
                map1.keys.forEach {
                    findStrobogrammatic(n - 2, "$it$left", "$right$it", ans, max)
                }
            }
            map2.keys.forEach {
                findStrobogrammatic(n - 2, "$it$left", "$right$it", ans, max)
            }
            map3.keys.forEach {
                findStrobogrammatic(n - 2, "$it$left", "$right${map3[it]}", ans, max)
            }
        }
    }
```
