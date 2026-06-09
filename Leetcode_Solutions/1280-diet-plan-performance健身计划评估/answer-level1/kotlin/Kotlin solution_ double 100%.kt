执行用时 :340 ms, 在所有 Kotlin 提交中击败了100.00%的用户
内存消耗 :44.7 MB, 在所有 Kotlin 提交中击败了100.00%的用户
```
    fun dietPlanPerformance(calories: IntArray, k: Int, lower: Int, upper: Int): Int {
        var grade = 0
        var calorie = 0
        if (k > 1) {
            for (i in 0..k - 2) {
                calorie += calories[i]
            }
        }
        for (i in k - 1 until calories.size) {
            calorie += calories[i]
            if (calorie < lower) {
                grade--
            } else if (calorie > upper) {
                grade++
            }
            calorie -= calories[i - k + 1]
        }
        return grade
    }
```
