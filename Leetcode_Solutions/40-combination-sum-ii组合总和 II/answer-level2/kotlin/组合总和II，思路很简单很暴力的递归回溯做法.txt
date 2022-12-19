### 解题思路
结合我写的[三数之和](https://leetcode-cn.com/problems/3sum/solution/yi-chong-hen-jian-dan-de-jie-fa-xiao-lu-bu-zen-yan/)和[组合总和](https://leetcode-cn.com/problems/combination-sum/solution/zu-he-zong-he-si-lu-hen-jian-dan-hen-bao-li-de-di-/)一起看就可以了，在这道题里效率居然意外的还很不错。
原谅本人口头表达实在不怎样。。。

### 代码

```kotlin
class Solution {
    val ans = ArrayList<ArrayList<Int>>()
    fun combinationSum2(candidates: IntArray, target: Int): List<List<Int>> {
        candidates.sort()
        solve(candidates, target, 0, 0, ArrayList())
        return ans
    }

    fun solve(array: IntArray, target: Int, sum: Int, index: Int, list: ArrayList<Int>) {
        for (i in index..array.lastIndex) {
            if (i != index && array[i] == array[i - 1]) {
                continue
            }
            val a = array[i]
            if (a + sum == target) {
                val l = ArrayList<Int>()
                l.addAll(list)
                l.add(a)
                ans.add(l)
                return
            } else if (a + sum > target) {
                return
            } else {
                list.add(a)
                solve(array, target, sum + a, i + 1, list)
                list.remove(a)
            }
        }
    }
}
```