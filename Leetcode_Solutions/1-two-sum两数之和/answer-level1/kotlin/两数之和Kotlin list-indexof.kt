思路。一个for循环，找到目标tager和数组里面差值。通过得到差值使用list特性去查询index是否有包含的角标如果不存在则返回-1，存在则即为正确答案（在这里需要判断当前角标不能循环角标去重）。当前for循环角标加上list对应的值即为结果：
```
fun twoSum2(nums: IntArray, target: Int): IntArray {
        var mun:Int
        var mark:Int
        var arrayMark = mutableListOf<Int>()
        for (i in nums.indices) {
            mun = target - nums[i]
            mark = nums.indexOf(mun)
            if (mark > -1 && i != mark) {
                System.out.println("===>"+i)
                System.out.println("===>"+mark)
                return intArrayOf(i,mark)
            }
        }
        return throw IllegalArgumentException("arrayMark.size = ${arrayMark.size}")
    }
```