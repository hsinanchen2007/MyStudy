### 解题思路
借助线段树实现，也可以调用python中的$sum()$函数

### 代码

```java []
class NumArray {
    
    // 线段树操作接口
    private interface Merger<E>{
        E merge(E a, E b);
    }

    // 私有线段树类
    private class SegmentTree<E>{
        private E[] tree;
        private E[] data;
        private Merger<E> merger;

        SegmentTree(E[] arr, Merger<E> merger){
            this.merger = merger;
            // 存储数据
            data = (E[]) new Object[arr.length];
            for(int i=0; i<arr.length; ++i){
                data[i] = arr[i];
            }

            // 分配树空间
            tree = (E[]) new Object[4*arr.length];
            buildSegmentTree(0, 0, data.length-1);
        }

        // 创建线段树，在treeIndex创建表示区间[l...r]的线段树
        private void buildSegmentTree(int treeIndex, int l, int r){
            if(l == r){
                tree[treeIndex] = data[l];
                return;
            }
            // 左子树
            int leftTreeIndex = 2*treeIndex+1;
            // 右子树
            int rightTreeIndex = 2*treeIndex+2;
            int mid = l+(r - l)/2;
            // 递归建立左子树和右子树
            buildSegmentTree(leftTreeIndex, l, mid);
            buildSegmentTree(rightTreeIndex, mid+1, r);

            tree[treeIndex] = merger.merge(tree[leftTreeIndex], tree[rightTreeIndex]);
        }

        // 查询区间[queryL, queryR]的merge()值
        E query(int queryL, int queryR){
            // 判断区间的合法性
            if(queryL<0 || queryL>=data.length || queryR < 0 || queryR>=data.length)
                throw new IllegalArgumentException("Error query Segement");
            return this.query(0, 0, data.length-1, queryL, queryR);
        }

        // 在root的[l, r]区间中查找[queryL, queryR]的值
        private E query(int root, int l, int r, int queryL, int queryR){
            if(l == queryL && r == queryR)
                return tree[root];
            int mid = l+(r - l)/2;
            int leftTreeIndex = 2*root+1;
            int rightTreeIndex = 2*root+2;
            
            // 如果[queryL, queryR]完全在右子区间
            if(queryL >= mid+1)
                return query(rightTreeIndex, mid+1, r, queryL, queryR);
            // 如果[queryL, queryR]完全在左子区间
            else if(queryR <= mid)
                return query(leftTreeIndex, l, mid, queryL, queryR);
            // mid \in [queryL, queryR]
            E l_res = query(leftTreeIndex, l, mid, queryL, mid);
            E r_res = query(rightTreeIndex, mid+1, r, mid+1, queryR);
            return merger.merge(l_res, r_res);
        }
    }
    
    // 考虑使用线段树实现
    private SegmentTree<Integer> segmentTree;
    private Integer[] data;

    public NumArray(int[] nums) {
        // 类型装箱：int -> Integer
        if(nums.length > 0){
            data = new Integer[nums.length];
            for(int i=0; i<nums.length; ++i)
                data[i] = nums[i];

            // 创建segmentTree对象, 指定merge()接口实现求和操作
            segmentTree = new SegmentTree<>(data, (a, b)-> a+b);
        }
    }
    
    public int sumRange(int i, int j) {
        if(segmentTree == null)
            throw new IllegalArgumentException("segmentTree is null");
        return segmentTree.query(i, j);
    }
}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */
```
```python []
class NumArray:
    # 注意函数会多次调用
    def __init__(self, nums: List[int]):
        self.nums = nums

    def sumRange(self, i: int, j: int) -> int:
        return sum(self.nums[i:j+1])
```
```c++ []
class NumArray {
public:
    NumArray(vector<int>& nums) {
        if(nums.size()<=0)
            return;
        this->dp = vector<int>(nums.size(), 0);
        dp[0] = nums[0];
        // dp数组记录前缀和
        for(int i=1; i<nums.size(); ++i)
            dp[i] = dp[i-1]+nums[i];
    }
    
    int sumRange(int i, int j) {
        return i==0?dp[j]:dp[j]-dp[i-1];
    }

private:
    vector<int> dp;
};

/*
class NumArray {
public:
    NumArray(vector<int>& nums) {
        this->data = nums;
    }
    
    int sumRange(int i, int j) {
        assert(i>=0 && j<data.size());
        int sum = 0;
        for(int k=i; k<=j; ++k){
            sum += data[k];
        }
        return sum;
    }
private: 
    vector<int> data;
};
*/
```