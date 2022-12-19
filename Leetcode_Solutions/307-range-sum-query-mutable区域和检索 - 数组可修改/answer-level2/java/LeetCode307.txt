### 解题思路
线段树：
执行用时：28ms
内存消耗：47MB
### 代码

```java
class NumArray {

    private interface Merger<E> {
        E merge(E a, E b);
    }

    private class SegmentTree<E> {
        private E[] data;
        private E[] tree;
        private Merger<E> merger;

        public SegmentTree(E[] arr, Merger<E> merger){
            data = (E[]) new Object[arr.length];
            this.merger = merger;

            System.arraycopy(arr, 0, data, 0, arr.length);
            tree = (E[]) new Object[4 * arr.length];
            buildSegmentTree(0, 0, data.length - 1);
        }

        //在treeIndex位置创建表示区间[l,r]的线段树
        private void buildSegmentTree(int treeIndex, int l, int r) {
            if (l == r) {
                tree[treeIndex] = data[l];
                return;
            }
            int leftTreeIndex = leftChild(treeIndex);
            int rightTreeIndex = rightChild(treeIndex);

            int mid =l + (r - l) / 2;
            buildSegmentTree(leftTreeIndex, l, mid);
            buildSegmentTree(rightTreeIndex, mid + 1, r);

            tree[treeIndex] = merger.merge(tree[leftTreeIndex], tree[rightTreeIndex]);
        }

        public E get(int index){
            if (index < 0 || index >= data.length)
                throw new IllegalArgumentException("Index is Illegal");
            return data[index];
        }

        public int getSize(){
            return data.length;
        }

        private int leftChild(int index){
            return 2 * index + 1;
        }

        private int rightChild(int index){
            return 2 * index + 2;
        }

        public E query(int queryL, int queryR){
            if (queryL < 0 || queryL >= data.length || queryR < 0 || queryR >= data.length || queryL > queryR)
                throw new IllegalArgumentException("Index is illegal");
            return query(0, 0, data.length - 1, queryL, queryR);
        }

        //在以treeIndex为根的线段树[l,r]的范围内，搜索区间[queryL, queryR]的值
        private E query(int treeIndex, int l, int r, int queryL, int queryR){
            if (l == queryL && r == queryR)
                return tree[treeIndex];
            int mid = l + (r - l) / 2;
            int leftTreeIndex = leftChild(treeIndex);
            int rightTreeIndex = rightChild(treeIndex);

            if (queryL >= mid + 1)
                return query(rightTreeIndex, mid + 1, r, queryL, queryR);
            else if (queryR <= mid)
                return query(leftTreeIndex, l, mid, queryL, queryR);

            E leftRes = query(leftTreeIndex, l, mid, queryL, mid);
            E rightRes = query(rightTreeIndex, mid + 1, r, mid + 1,queryR);

            return merger.merge(leftRes, rightRes);
        }

        //将Index位置的
        public void set(int index, E e){
            if (index < 0 || index >= data.length)
                throw new IllegalArgumentException("Index is ilegal");
            data[index] = e;
            set(0, 0, data.length - 1,index , e);
        }

        private void set(int treeIndex, int l, int r ,int index ,E e){
            if (l == r){
                tree[treeIndex] = e;
                return;
            }
            int mid = l + (r - l) / 2;
            int leftTreeIndex = leftChild(treeIndex);
            int rightTreeIndex = rightChild(treeIndex);

            if (index >= mid + 1)
                set(rightTreeIndex,mid + 1 , r ,index ,e);
            else
                set(leftTreeIndex ,l ,mid , index, e);

            tree[treeIndex] = merger.merge(tree[leftTreeIndex], tree[rightTreeIndex]);
        }

        @Override
        public String toString() {
            StringBuilder res = new StringBuilder();
            res.append('[');
            for (int i = 0; i < tree.length; i++) {
                if(tree[i] != null)
                    res.append(tree[i]);
                if(tree[i] == null)
                    res.append("null");

                if (i != tree.length - 1)
                    res.append(' ');
            }
            res.append(']');
            return res.toString();
        }
    }

    SegmentTree<Integer> segmentTree;
    public NumArray(int[] nums) {
        if (nums.length > 0){
            Integer[] data = new Integer[nums.length];
            for (int i = 0; i < nums.length; i++) {
                data[i] = nums[i];
            }
            segmentTree = new SegmentTree<Integer>(data, (a, b) -> a + b);
        }
    }

    public void update(int i, int val) {
        if (segmentTree == null)
            throw new IllegalArgumentException("Segment Tree is illegal");
        segmentTree.set(i, val);
    }

    public int sumRange(int i, int j) {
        if (segmentTree == null)
            throw new IllegalArgumentException("Segment Tree is illegal");
        return segmentTree.query(i, j);
    }
}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */
```