    class Node {
        int sum;
        int start;
        int end;
        Node left;
        Node right;

        Node(int sum, int start, int end, Node left, Node right) {
            this.sum = sum;
            this.start = start;
            this.end = end;
            this.left = left;
            this.right = right;
        }
    }

    private Node root;

    public NumArray(int[] nums) {
        if (nums.length == 0) {
            return;
        }
        root = buildTree(nums, 0, nums.length - 1);
    }

    private Node buildTree(int[] nums, int start, int end) {
        if (start == end) {
            // leaf node
            return new Node(nums[start], start, end, null, null);
        }
        int mid = (start + end) / 2;
        Node left = buildTree(nums, start, mid);
        Node right = buildTree(nums, mid + 1, end);

        return new Node(left.sum + right.sum, start, end, left, right);
    }

    public void update(int i, int val) {
        updateValue(root, i, val);
    }

    private void updateValue(Node root, int index, int value) {
        if (root.start == root.end) {
            root.sum = value;
            return;
        }
        int mid = (root.start + root.end) / 2;
        if (index <= mid) {
            updateValue(root.left, index, value);
        } else {
            updateValue(root.right, index, value);
        }
        root.sum = root.left.sum + root.right.sum;
    }

    public int sumRange(int i, int j) {
        return query(root, i, j);
    }

    private int query(Node root, int i, int j) {
        if ((root.end < i) || (root.start > j)) {
            return 0;
        } else if (i <= root.start && j >= root.end) {
            return root.sum;
        }
        return query(root.left, i, j) + query(root.right, i, j);
    }