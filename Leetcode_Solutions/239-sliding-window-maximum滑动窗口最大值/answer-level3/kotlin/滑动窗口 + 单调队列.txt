使用一个单调队列保存索引，队列的头部是当前窗口最大值的索引，尾部是最小值的索引；
每移动一次，更新队列，当前窗口的最大值就是队列头部索引对应的值；
更新队列的方式：把当前元素和窗口中的最小值做对比，如果当前值大，抛出队列末尾的元素，继续比较，直到当前元素比队列末尾的元素小或者队列为空。

    class Solution {
        fun maxSlidingWindow(nums: IntArray, k: Int): IntArray {
            
            val n = nums.size

            if (k <= 0 || n < k) {
                return IntArray(0)
            }

            // 保存结果
            val res = IntArray(n - k + 1)

            // 单调队列，用于保存索引，头部是当前窗口内的最大值的索引，尾部是当前窗口内最小值的索引
            val indexQueue = LinkedList<Int>()

            // 保存结果的索引
            var resIndex = -1

            for (i in 0 until n) {
                // 保证尾部元素，一定是最小的。
                // 如果即将进入的这个元素，比已有的最小值要大，那把它加进来队列就不是单调的了，所以先把已有的最小值抛出
                while(!indexQueue.isEmpty() && nums[indexQueue.peekLast()] <= nums[i]) {
                    indexQueue.pollLast()
                }

                // 在尾部加入当前元素的索引
                indexQueue.addLast(i)

                // 判断窗口是否已经滑过了最大值的索引
                if (i - k >= indexQueue.peekFirst()) {
                    indexQueue.pollFirst()
                }

                // 记录结果
                resIndex = i - k + 1
                if (resIndex >= 0) {
                    res[resIndex] = nums[indexQueue.peekFirst()]
                }
            }

            return res
        }
    }