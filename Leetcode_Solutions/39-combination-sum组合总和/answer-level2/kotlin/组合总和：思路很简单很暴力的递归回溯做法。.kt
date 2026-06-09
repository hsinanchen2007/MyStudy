### 解题思路
思路很简单很暴力的递归回溯做法，本人语言表达能力不好，直接上例子步骤：
```
输入：candidates = [2, 3, 6, 7], target = 7

list = [] 保存一种组合
sum 累加值
index 遍历candidates时开始的下标

递归层1) index=0 -> 取candidates['2',3,6,7] -> list=[2] -> sum=2 -> sum<target ->递归
递归层2) index=0 -> 取candidates['2',3,6,7] -> list=[2,2] -> sum=4 -> sum<target ->递归
递归层3) index=0 -> 取candidates['2',3,6,7] -> list=[2,2,2] -> sum=6 -> sum<target ->递归
递归层4) index=0 -> 取candidates['2',3,6,7] -> list=[2,2,2,2] -> sum=8 -> sum>target ->回退
递归层3) index=1 -> 取candidates[2,'3',6,7] -> list=[2,2,3] -> sum=7 -> sum=target -> 记录[2,2,3]
递归层3) index=2 -> 取candidates[2,3,'6',7] -> list=[2,2,6] -> sum=10 -> sum>target ->回退
递归层2) index=1 -> 取candidates[2,'3',6,7] -> list=[2,3] -> sum=5 -> sum<target ->递归
递归层3) index=1 -> 取candidates[2,'3',6,7] -> list=[2,3,3] -> sum=8 -> sum>target ->回退
递归层2) index=2 -> 取candidates[2,3,'6',7] -> list=[2,6] -> sum=8 -> sum>target ->回退
递归层1) index=1 -> 取candidates[2,'3',6,7] -> list=[3] -> sum=3 -> sum<target ->递归
递归层2) index=1 -> 取candidates[2,'3',6,7] -> list=[3,3] -> sum=6 -> sum<target ->递归
后续省略

```
如果每次递归都是从头遍历`candidates`的话，那么得到的结果就会有重复，所以利用`index`避免每次都从头开始遍历，以达到去重的目的。
这种解法效率不怎样，但至少一遍过了。本人表达能力不好，已经尽力描述了。。。

### 代码

```kotlin
class Solution {
    val ans = ArrayList<ArrayList<Int>>()
    fun combinationSum(candidates: IntArray, target: Int): List<List<Int>> {
        candidates.sort()
        solve(candidates, target, 0, 0, ArrayList())
        return ans
    }

    fun solve(array: IntArray, target: Int, sum: Int, index: Int, list: ArrayList<Int>) {
        for (i in index..array.lastIndex) {
            if (array[i] + sum == target) {
                val l = ArrayList<Int>()
                l.addAll(list)
                l.add(array[i])
                ans.add(l)
                return
            } else if (array[i] + sum > target) {
                return
            } else {
                list.add(array[i])
                solve(array, target, sum + array[i], i, list)
                list.remove(array[i])
            }
        }
    }
}
```