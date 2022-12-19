### 解题思路
> 想法是非常简单的，主要难题是过滤重复的元素以避免超时。

- 第一步：为了接下来过滤重复元素，需要先将数据进行排序

- 第二步：首先考虑 `“两数之和为0”` 的情况，我们可以使用两个下标 *i* 和 *j* ，如下作两层循环:
```kotlin
fun twoSum(nums: IntArray): List<List<Int>> {
    val ans = ArrayList<ArrayList<Int>>()
    nums.sort()
    for (i in 0 until nums.size - 1) {
        if (i != 0 && nums[i] == nums[i - 1]) {
            continue
        }
        for (j in i + 1 until nums.size) {
            if (nums[i] + nums[j] == 0) {
                ans.add(arrayListOf(nums[i], nums[j]))
                break
            }
        }
    }
    return ans
}
```
当固定 *i* 移动 *j* 时，如果此时 `num[i] + num[j] == 0` ，那么我们可以认为已经找到了符合要求的一对数并可以停止 *j* 后面的移动，然后移动 *i* 。
移动 *i* 时如果 *i* 指向的数和 *i* 指向的前一个数相同，我们认为已经有对应的结果，所以可以跳过，继续往下移动。重复这个过程直到结束就可以获得结果。

- 第三步：同理，我们考虑 `“三数之和为0”` 的时候，其实可以认为是在 `“两数之和为0”` 的基础上再在外面嵌套一层循环，并将判定结果等价为 `num[i] + num[j] == -num[k]` 。如下作三层循环：
```kotlin
class Solution {
    fun threeSum(nums: IntArray): List<List<Int>> {
        val ans = ArrayList<ArrayList<Int>>()
        nums.sort()
        for (i in 0 until nums.size - 2) {
            if (i != 0 && nums[i] == nums[i - 1]) {
                continue
            }
            for (j in i + 1 until nums.size - 1) {
                if (j != i + 1 && nums[j] == nums[j - 1]) {
                    continue
                }
                for (k in j + 1 until nums.size) {
                    if (nums[i] + nums[j] + nums[k] == 0) {
                        ans.add(arrayListOf(nums[i], nums[j], nums[k]))
                        break
                    }
                }
            }
        }
        return ans
    }
}
```
当 *k* 找到之后，我们认为与 `num[i] + num[j]` 对应的数已经找到，可以停止k后续的移动，然后移动 *j* 。移动 *j* 时如果 *j* 指向的数和 *j* 指向的上一个数相同，我们认为已经有了对应的结果，所以可以跳过，继续往下移动，重复这个过程直到 *j* 移动到末尾，然后移动 *i* 。 *i* 的判断逻辑和 *j* 一样，重复这个过程直到结束就可以获得结果。

`“四数之和”` 也可以这么做，同样效率不高，但能过。
