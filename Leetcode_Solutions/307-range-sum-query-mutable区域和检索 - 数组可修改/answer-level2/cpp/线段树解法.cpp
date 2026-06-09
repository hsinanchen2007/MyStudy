线段树解法

```
typedef struct SegTreeNode {
    int start, end, sum;
    SegTreeNode *left, *right;
    SegTreeNode(int start, int end) : left(NULL), right(NULL) {
        this->start = start;
        this->end = end;
    }
} * SegTree;

class NumArray {
   public:
    NumArray(vector<int>& nums) {
        this->segTree = buildSegTree(nums, 0, nums.size() - 1);
    }

    void update(int i, int val) { update(this->segTree, i, val); }

    int sumRange(int i, int j) { return sumRange(this->segTree, i, j); }

   private:
    // 构建线段树
    SegTree buildSegTree(vector<int>& nums, int start, int end) {
        if (start > end) return NULL;
        SegTree root = new SegTreeNode(start, end);
        if (start == end) {
            root->sum = nums[start];
            return root;
        }
        int mid = start + (end - start) / 2;
        root->left = buildSegTree(nums, start, mid);
        root->right = buildSegTree(nums, mid + 1, end);
        root->sum = root->left->sum + root->right->sum;
        return root;
    }

    // 更新节点值
    int update(SegTree root, int i, int val) {
        if (!root) return 0;

        // i 不在区间内，直接返回节点值
        if (i < root->start || root->end < i) return root->sum;

        // 找到了目标节点，更新值并返回
        if (root->start == root->end) {
            if (root->start == i) root->sum = val;
            return root->sum;
        }

        // 递归更新左右子树并返回更新后的结果
        root->sum = update(root->left, i, val) + update(root->right, i, val);
        return root->sum;
    }

    // 求区间和
    int sumRange(SegTree root, int start, int end) {
        if (!this->segTree) return 0;
        
        // 区间完全匹配，直接返回结果
        if (root->start == start && root->end == end) return root->sum;

        // 区间不匹配，需要进行二分查找
        int mid = root->start + (root->end - root->start) / 2;
        // 在左边[start, mid]
        if (end <= mid) return sumRange(root->left, start, end);
        // 在右边 [mid+1, right]
        if (start >= mid + 1) return sumRange(root->right, start, end);
        // 跨左右区间时，分别求左右区间和
        return sumRange(root->left, start, mid) +
               sumRange(root->right, mid + 1, end);
    }

    SegTree segTree;
};
```
