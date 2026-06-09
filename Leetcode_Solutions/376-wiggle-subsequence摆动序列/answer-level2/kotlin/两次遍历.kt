两次遍历
```
fun wiggleMaxLength(nums: IntArray): Int {
        val length = nums.size
        if (length < 2) {
            return length
        }
        //用一个数组记录当前数据和上一个数据差的情况，差有三种情况，正数，负数，零
        //nums[i] > nums[i-1] : 1
        //nums[i] < nums[i-1] : -1
        //nums[i] == nums[i-1] : 0
        var flags = IntArray(length)  
        for (i in 0 until length - 1) {
            flags[i] = if (nums[i + 1] - nums[i] > 0) 1 else if(nums[i + 1] - nums[i] < 0) -1 else 0
        }
        var num = length
        var curFlag = 0;
        for (i in 1 until length - 1) {
            if (flags[i] == 0) { //和上一个数相等，去掉一个
                num--
            } else if (flags[i] == curFlag) { // 连续正数或者负数，去掉一个
                num--
            } else {
                curFlag = flags[i]
            }
        }
        if (flags[0] == 0) {
            num--
        }
        return num
    }
```
