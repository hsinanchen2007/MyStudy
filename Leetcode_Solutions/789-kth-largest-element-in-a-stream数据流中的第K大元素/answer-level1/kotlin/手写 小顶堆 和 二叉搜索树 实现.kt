小顶堆实现原理：

第k大的数就是数组按照从大到小的顺序下的第k位
利用小顶堆的特性，堆只保留k个元素，第1大到第k大的数都在堆里，第k大的数正好是堆顶
如果要插入的数比堆顶元素大，堆顶元素就变为了第k+1大的数，应该从堆中舍弃，于是就将堆顶元素替换为新元素，再调整堆使其满足小顶堆的特性，此时堆顶依然是第k大的数
如果要插入的数比堆顶元素小，则忽略，因为第k+1大、k+2大等等的数字我们并不关心
建立堆的时间是O(n)，一次向下调整堆的时间复杂度是O(log2 k)


```
class KthLargest(
    private val k: Int,
    nums: IntArray
) {
    /**
     * 小根堆
     */
    private val heap: IntArray

    /**
     * 原始堆的长度
     */
    private var length = nums.size

    init {
        // 题意限制 nums 的长度≥ k-1，即 k 的最大值为 nums 的长度 + 1
        // 令 n = nums 的长度，当 k = n + 1 时，给堆预留一个存储空间，用于第一次add时把值放入堆中，以便统计第k大的数
        heap = if (k == length + 1) {
            IntArray(length + 1).apply {
                nums.copyInto(this)
            }
        } else nums

        // 构建小顶堆
        buildMinHeap(heap, length)

        // 堆中只保留k个元素，不断的删除堆顶元素，把堆底元素换到堆顶，再调整堆
        keepHeapSize(heap, length, k)
    }

    fun add(`val`: Int): Int {
        // 题意限制 nums 的长度≥ k-1，即 k 的最大值为 nums 的长度 + 1
        // 当k超过 nums 的长度，刚好是 nums 的长度 + 1 时，在第一次add时，要把add的值放入堆中，以便后续比较
        if (length < heap.size) {
            // 堆顶最小元素放到末尾，下面会再把新元素插入插入堆顶，再从堆顶向下调整堆
            heap[length] = heap[0]
            // 改变原始堆长度
            length++
        } else { // 此时 k <= n，可以保证堆顶元素就是第k大的数
            // 堆顶元素是最小的元素，堆有k个数，堆的其他元素都比堆顶元素大，那么堆顶元素就是第k大的数
            // 如果要插入的数值小于等于最小的元素，堆顶元素依然是第k大的，就要插入的数值就不用插入堆中了
            if (`val` <= heap[0]) {
                return heap[0]
            }
        }

        // 如果要插入的数值大于最小的元素，当前堆顶元素就不是最小的了，也就是不是第k大的了，就要调整堆了
        // 此时应该将新插入的数放入堆顶，舍弃原来最小的数，因为原来最小的数（原堆顶元素）一定不是第k大的数了，还放在大小为k的堆里没有意义
        heap[0] = `val`
        // 新元素插入堆顶后，可能会破坏堆，需要向下调整
        sink(heap, 1, k)
        // 调整后的堆顶元素就是最小的元素，也就是第k大的数
        return heap[0]
    }

    /**
     * 保持堆[nums]为指定的大小[size]
     */
    private fun keepHeapSize(nums: IntArray, originalSize: Int, size: Int) {
        if (originalSize <= size) {
            return
        }
        // 依次删除堆顶元素
        for (length in originalSize downTo size + 1) {
            // 将堆末尾的数放到堆顶，覆盖原来的数，以达到删除堆顶元素的效果
            nums.swap(0, length - 1)
            // 从堆顶开始向下调整堆
            // 最后一个元素已删除，所以不在堆调整范围内
            sink(nums, 1, length - 1)
        }
        // 末尾空余的位置不管，k就是堆的大小，是小于等于原堆大小的
    }

    /**
     * 构建初始的小顶堆
     */
    private fun buildMinHeap(nums: IntArray, length: Int) {
        // 从最后一个非叶子结点开始到根节点，不停的向下调整堆，最后整体就是小根堆，为什么建堆是这样遍历需要复习堆排序的知识
        for (parent in length / 2 downTo 1) {
            sink(nums, parent, length)
        }
    }

    /**
     * 从第[k]个数开始上向下调整堆[nums]，堆的大小为[length]
     */
    private fun sink(nums: IntArray, k: Int, length: Int) {
        var parent = k
        while (parent <= length / 2) {
            var child = parent * 2
            // child 和 parent 都是编号，在数组的实际索引要减1
            if (child < length && nums[child - 1] > nums[child]) child++
            if (nums[parent - 1] <= nums[child - 1]) break
            nums.swap(parent - 1, child - 1)
            parent = child
        }
    }

    /**
     * 定义数组IntArray的扩展函数swap，用以交换数组内两个位置[i]和[j]的元素
     */
    private fun IntArray.swap(i: Int, j: Int) {
        val tmp = this[i]
        this[i] = this[j]
        this[j] = tmp
    }
}
```


二叉搜索树法原理参见二叉搜索树探索卡片
https://leetcode-cn.com/explore/learn/card/introduction-to-data-structure-binary-search-tree/66/conclusion/182/
`鉴于我们同时需要插入和搜索操作，为什么不考虑使用一个二叉搜索树结构存储数据呢？
我们知道，对于二叉搜索树的每个节点来说，它的左子树上所有结点的值均小于它的根结点的值，右子树上所有结点的值均大于它的根结点的值。
换言之，对于二叉搜索树的每个节点来说，若其左子树共有m个节点，那么该节点是组成二叉搜索树的有序数组中第m + 1个值。`

```
class KthLargest(k: Int, nums: IntArray) {
    private var bst: TreeNode? = null
    private val kth = k

    init {
        nums.forEach {
            bst = BST.insert(bst, it)
        }
    }

    fun add(`val`: Int): Int {
        bst = BST.insert(bst, `val`)
        val node = BST.search(bst, kth)
        return node!!.`val`
    }

    object BST {
        fun insert(root: TreeNode?, value: Int): TreeNode? {
            if (root == null) {
                return TreeNode(value, 1)
            }
            if (value < root.`val`) {
                root.left = insert(root.left, value)
            } else if (value > root.`val`) {
                root.right = insert(root.right, value)
            }
            // 重复元素不添加新节点，只是更新当前节点的计数
            root.count++
            return root
        }

        fun search(root: TreeNode?, k: Int): TreeNode? {
            if (root == null) {
                return root
            }
            // 左子树节点数量
            val leftNodeCount = root.left?.count ?: 0
            // 右子树节点数量
            val rightNodeCount = root.right?.count ?: 0
            // 当前节点数量，当前节点可能存在重复的
            val currentNodeCount = root.count - leftNodeCount - rightNodeCount
            // 根据二叉搜索树特点，大于当前节点的数都在右子树
            // 如果k小于等于右子树的节点数，说明第k大的数在右子树，要去右子树寻找，否则要在当前节点和左子树中寻找
            return when {
                k <= rightNodeCount -> search(root.right, k)
                k > rightNodeCount + currentNodeCount -> search(root.left, k - rightNodeCount - currentNodeCount)
                else -> root
            }
        }
    }

    class TreeNode(var `val`: Int, var count: Int) {
        var left: TreeNode? = null
        var right: TreeNode? = null
    }
}
```