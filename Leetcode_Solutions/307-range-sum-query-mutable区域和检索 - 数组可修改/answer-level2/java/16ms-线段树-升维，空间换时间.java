![image.png](https://pic.leetcode-cn.com/dccdf88d35d1128995b197b8d7039c607bb9a3db99a2ddc79d2e954b72ace2a9-image.png)
 
在 update 函数与 sumRange 函数的调用次数是均匀分布的，采用线段树可以在花费一些额外空间的情况下，把这两个操作的时间复杂度都控制在O(log(n))

```
public class NumArray {
    private int[] tree;
    private int[] nums;
    private int len;

    public NumArray(int[] nums) {
        this.nums = nums;
        this.len = nums.length;
        this.tree = new int[4 * this.len];
        buildSegTree(0, 0, this.len - 1);
    }

    public void update(int i, int val) {
        this.updateSegTree(0, 0, this.len - 1, i, val);
    }

    public int sumRange(int i, int j) {
        return querySegTree(0, 0, this.len - 1, i, j);
    }

    private void buildSegTree(int node, int start, int end) {
        if (end < start) {
            return;
        }
        if (start == end) {
            tree[node] = nums[start];
        } else {
            int mid = start + (end - start) / 2;
            int leftNode = 2 * node + 1;
            int rightNode = 2 * node + 2;

            buildSegTree(leftNode, start, mid);
            buildSegTree(rightNode, mid + 1, end);

            tree[node] = tree[leftNode] + tree[rightNode];
        }
    }

    private void updateSegTree(int node, int start, int end, int idx, int val) {
        if (start == end) {
            this.nums[idx] = val;
            this.tree[node] = val;
        } else {
            int mid = start + (end - start) / 2;
            int leftNode = 2 * node + 1;
            int rightNode = 2 * node + 2;

            if (idx >= start && idx <= mid) {
                updateSegTree(leftNode, start, mid, idx, val);
            } else {
                updateSegTree(rightNode, mid + 1, end, idx, val);
            }

            tree[node] = tree[leftNode] + tree[rightNode];
        }
    }

    private int querySegTree(int node, int start, int end, int L, int R) {
        if (end < L || start > R) {
            return 0;
        } else if ((L <= start && end <= R) || start == end) {
            return tree[node];
        } else {
            int mid = start + (end - start) / 2;
            int leftNode = 2 * node + 1;
            int rightNode = 2 * node + 2;
            return querySegTree(leftNode, start, mid, L, R) + querySegTree(rightNode, mid + 1, end, L, R);
        }
    }
}
```

