### 解题思路
此处撰写解题思路
1、利用数组的值构建一颗平衡二叉树
2、利用树的递归创建出来所有的节点
3、利用二分法填值

### 代码

```java
class NumArray {
    Tree root;
    
    public NumArray(int[] nums) {
        if (nums == null || nums.length < 1) {
            return;
        }
        root = new Tree(0, nums.length - 1);
        buildTree(root, nums, 0, nums.length - 1);
    }

    public void update(int i, int val) {
        set(i, val, root);
    }

    public int sumRange(int i, int j) {
        if (root == null) {
            return 0;
        }
        int aa = range(i, j, root);
        return aa;
    }

    private void buildTree(Tree root, int[] num, int start, int end) {
        if (start == end) {
            root.start = start;
            root.end = end;
            root.sum = num[start];
            return;
        }
        int mid = (start + end) / 2;
        root.left = new Tree(start, mid);
        buildTree(root.left, num, start, mid);

        root.right = new Tree(mid + 1, end);
        buildTree(root.right, num, mid + 1, end);
        root.sum = root.left.sum + root.right.sum;
    }

    private void set(int i, int val, Tree root) {
        if (root.start == root.end) {
            if (i == root.start) {
                root.sum = val;
                return;
            }
        }
        int mid = (root.start + root.end) / 2;
        if (i <= mid) {
            set(i, val, root.left);
        } else {
            set(i, val, root.right);
        }
        root.sum = root.left.sum + root.right.sum;
    }

    private int range(int i, int j, Tree root) {
        if (i == root.start && j == root.end) {
            return root.sum;
        }

        int mid = (root.start + root.end) / 2;
        if (j <= mid) {
            return range(i, j, root.left);
        }
        if (i > mid) {
            return range(i, j, root.right);
        }
        return range(i, mid, root.left) + range(mid + 1, j, root.right);
    }

    private class Tree {
        int start;

        int end;

        int sum;

        Tree left;

        Tree right;

        public Tree(int start, int end) {
            this.start = start;
            this.end = end;
        }
    }
}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */
```