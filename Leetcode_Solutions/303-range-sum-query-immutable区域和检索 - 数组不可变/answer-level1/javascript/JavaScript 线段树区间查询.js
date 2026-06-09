// ```javascript

class SegmentTree {
    constructor(options) {
        if (!options.array || typeof options.merger !== 'function') {
            throw new Error('options error!')
        }
        this.array = options.array || []  // 用户传递来的数组
        this.merger = options.merger

        // 初始化 tree的最大容积
        this.tree = new Array(4 * this.array.length)

        // 构建线段树
        this.buildSegmentTree(0, 0, this.array.length - 1)
    }

    /**
     * 在treeIndex的位置创建标示区间[l, ..., r]的线段树
     * @param treeIndex
     * @param l
     * @param r
     */
    buildSegmentTree(treeIndex, l, r) {
        if (r < 0) {
            return
        }

        // 还剩一个节点的时候, 递归结束
        if (l === r) {
            this.tree[treeIndex] = this.array[l]
            return
        }

        const leftTreeIndex = SegmentTree.leftChild(treeIndex)
        const rightTreeIndex = SegmentTree.rightChild(treeIndex)
        const mid = Math.floor(l + (r - l) / 2)

        // 在左子树 leftTreeIndex位置创建区间[l, mid]的线段树
        this.buildSegmentTree(leftTreeIndex, l, mid)

        // 在右子树 rightTreeIndex位置创建区间[mid + 1, r]的线段树
        this.buildSegmentTree(rightTreeIndex, mid + 1, r)

        this.tree[treeIndex] = this.merger(this.tree[leftTreeIndex], this.tree[rightTreeIndex])
    }

    /**
     * 查询区间 [queryL, queryR]的值
     * @param queryL
     * @param queryR
     * @return {number}
     */
    query(queryL, queryR) {
        // 0 1
        if (
            queryL < 0
            || queryL > this.array.length
            || queryR < 0
            || queryR > this.array.length
            || queryL > queryR
        ) {
            return []
        }

        return this._query(0, 0, this.array.length - 1, queryL, queryR)
    }

    /**
     * 在以 treeIndex 为根的线段树中 [l...r]的范围里, 搜索区间[queryL, queryR]的值
     * @param treeIndex
     * @param l
     * @param r
     * @param queryL
     * @param queryR
     * @return {*}
     * @private
     */
    _query(treeIndex, l, r, queryL, queryR) {
        // 递归函数的结束条件
        if (l === queryL && r === queryR) {
            return this.tree[treeIndex]
        }
        const mid = Math.floor(l + (r - l) / 2)
        const leftTreeIndex = SegmentTree.leftChild(treeIndex)
        const rightTreeIndex = SegmentTree.rightChild(treeIndex)

        // 如果查询区间在右子树
        if (queryL >= mid + 1) {
            return this._query(rightTreeIndex, mid + 1, r, queryL, queryR)
        }
        // 如果查询区间在左子数
        else if (queryR <= mid) {
            return this._query(leftTreeIndex, l, mid, queryL, queryR)
        }
        // 查询区间 queryL .. queryR的内容即在左子树,又在🈶右子树
        else {
            const leftResult = this._query(leftTreeIndex, l, mid, queryL, mid)
            const rightResult = this._query(rightTreeIndex, mid + 1, r, mid + 1, queryR)
            return this.merger(leftResult, rightResult)
        }
    }

    /**
     * 线段树区间更新
     * @param index
     * @param e
     */
    set(index, e) {
        if (index < 0 || index > this.array.length) {
            throw new Error('index error!')
        }

        // 数组对应的下标更新
        this.array[index] = e

        // 内部维护的一份 tree数据更新, 且更新结果影响当前更新节点的所有父级,重新 merger
        this._set(0, 0, this.array.length, index, e)
    }

    _set(treeIndex, l, r, index, e) {
        // 已找到更新的节点
        if (l === r) {
            this.tree[treeIndex] = e
            return
        }

        const mid = Math.floor(l + (r - l) / 2)
        const leftTreeIndex = SegmentTree.leftChild(treeIndex)
        const rightTreeIndex = SegmentTree.rightChild(treeIndex)
        /**
         *  l >= mid + 1
         *  r <= mid
         *  [1,2,3,4,5]
         *  mid = 2
         *  index 2
         */
        if (index >= mid + 1) {
            this._set(rightTreeIndex, mid + 1, r, index, e)
        }
        else if (index <= mid) {
            this._set(leftTreeIndex, l, mid, index, e)
        }

        this.tree[treeIndex] = this.merger(this.tree[leftTreeIndex], this.tree[rightTreeIndex])
    }

    getSizie() {
        return this.array.length
    }

    /**
     * 根据下标获取 array的数据
     * @param {number} index
     */
    get(index) {
        if (index < 0 || index > this.array.length) {
            throw new Error(`${index} min&&max`)
        }
        return this.array[index]
    }

    /**
     * 一个索引所表示的元素左孩子节点的索引
     * @param index
     * @return {number}
     */
    static leftChild(index) {
        return index * 2 + 1
    }

    /**
     * 一个索引所表示的元素右孩子节点的索引
     * @param index
     * @return {number}
     */
    static rightChild(index) {
        return index * 2 + 2
    }
}
/**
 * @param {number[]} nums
 */
var NumArray = function(nums) {
    const options = {
        array: nums,
        merger: function (n, m) {
            return n + m
        }
    }

    this.seg = new SegmentTree(options)
};

/**
 * @param {number} i
 * @param {number} j
 * @return {number}
 */
NumArray.prototype.sumRange = function(i, j) {
    return this.seg.query(i, j)
};

/** 
 * Your NumArray object will be instantiated and called as such:
 * var obj = new NumArray(nums)
 * var param_1 = obj.sumRange(i,j)
 */
// ```