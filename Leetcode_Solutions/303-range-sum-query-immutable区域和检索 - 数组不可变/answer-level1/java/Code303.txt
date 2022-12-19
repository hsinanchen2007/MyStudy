### 解题思路
线段树解决

### 代码

```java
class NumArray {
    private int[] data;
    private int[] tree;

    public NumArray(int[] nums) {
        if (nums.length == 0) {
            return;
        }

        data = new int[nums.length];
        for (int i = 0; i < data.length; i++) {
            data[i] = nums[i];
        }

        tree = new int[4 * data.length];

        buildSegmentTree(0, 0, data.length - 1);
    }

    private void buildSegmentTree(int treeIndex, int l, int r) {
        if (l == r) {
            tree[treeIndex] = data[l];
            return;
        }

        int mid = l + (r - l) / 2;
        int leftIndex = getLeftIndex(treeIndex);
        int rightIndex = getRightIndex(treeIndex);

        buildSegmentTree(leftIndex, l, mid);
        buildSegmentTree(rightIndex, mid + 1, r);

        tree[treeIndex] = tree[leftIndex] + tree[rightIndex];
    }

    private int getLeftIndex(int index) {
        return 2 * index + 1;
    }

    private int getRightIndex(int index) {
        return 2 * index + 2;
    }

    public int sumRange(int i, int j) {   

        return realSumRange(0, 0, data.length - 1, i, j);
    }

    private int realSumRange(int treeIndex, int l, int r, int queryL, int queryR) {
        if (l == queryL && r == queryR) {
            return tree[treeIndex];
        }

        int mid = l + (r - l) / 2;
        int leftIndex = getLeftIndex(treeIndex);
        int rightIndex = getRightIndex(treeIndex);

        if (queryL > mid) {
            return realSumRange(rightIndex, mid + 1, r, queryL, queryR);
        }
        else if (queryR <= mid) {
            return realSumRange(leftIndex, l, mid, queryL, queryR);
        }
        else {
            int leftResult = realSumRange(leftIndex, l, mid, queryL, mid);
            int rightResult = realSumRange(rightIndex, mid + 1, r, mid + 1, queryR);
            return leftResult + rightResult;
        }
    }
}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */
```