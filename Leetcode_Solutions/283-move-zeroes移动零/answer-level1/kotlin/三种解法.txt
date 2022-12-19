
### 第一种
```
fun moveZeroes(nums: IntArray): Unit {
    if (nums.size == 1) return
    var i = 0
    var j = 1
    var t = 0
    while (j < nums.size && i < nums.size) {
        //找到第一个零的数字
        while (i < nums.size - 1 && nums[i] != 0) i++
        if (i == nums.size - 1) return
        j = i + 1
        //找到零后面的非零数字
        while (j < nums.size - 1 && nums[j] == 0) j++
        if (nums[j] == nums.size - 1 && nums[j] == 0) return
        val t = nums[j]
        nums[j] = nums[i]
        nums[i] = t
        i++
        j++
    }
}
```
### 第二种
```
fun moveZeroes(nums: IntArray): Unit {
    var index = 0
    nums.forEach {
        if (it != 0) {
            nums[index++] = it
        }
    }
    while (index < nums.size) {
        nums[index++] = 0
    }
}
```

### 第三种
* 这一种是针对第二种的优化
```
fun moveZeroes(nums: IntArray): Unit {
    var index = 0
    for ((i, value) in nums.withIndex()) {
        if (value != 0) {
            nums[i] = nums[index]
            nums[index++] = value
        }
    }
}
```

