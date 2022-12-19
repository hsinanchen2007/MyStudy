class Solution {
    fun maxSlidingWindow(nums: IntArray, k: Int): IntArray {

        val n = nums.size

        // 前提条件
        if (n < k || k <= 0) {
            return IntArray(0)
        }

        // 用于保存索引的双向队列，头部是最大值的索引，尾部是最小值的索引
        val indexQueue = LinkedList<Int>()

        // 保存结果
        val res = IntArray(n - k + 1)
        var resIndex = -1;
        for (i in 0 until n) {
            
            while(!indexQueue.isEmpty() && nums[indexQueue.peekLast()] <= nums[i]) {
                indexQueue.pollLast()
            }

            // 添加到尾部
            indexQueue.addLast(i)

            // 判断头部是否需要出队列
            if (i - k >= indexQueue.peekFirst()) {
                indexQueue.pollFirst()
            }

            // 判断是否需要添加到结果中
            resIndex = i - k + 1
            if (resIndex >= 0) {
                res[resIndex] = nums[indexQueue.peekFirst()]
            }
        }

        return res
    }
}