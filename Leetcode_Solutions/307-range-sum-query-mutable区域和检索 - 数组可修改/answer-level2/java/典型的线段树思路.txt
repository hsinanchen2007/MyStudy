### 解题思路
此处撰写解题思路

### 代码

```java
class NumArray {

    private int [] tree = new int [100001];
    private int [] nums ;

    public NumArray(int[] nums) {
        if (nums == null || nums.length == 0) {
            return;
        }
        int length = nums.length;
        this.nums = nums;
        build(nums,tree,0,0,length - 1);
    }

    private void build(int [] nums,int [] tree, int node, int start,int end) {
        if (start == end) {
            tree[node] = nums[start];
            return ;
        }
        int mid = (start + end) / 2;
        int leftNode = 2 * node + 1;
        int rightNode = 2 * node + 2;
        build(nums,tree,leftNode,start,mid);
        build(nums,tree,rightNode,mid + 1, end);
        tree[node] = tree[leftNode] + tree[rightNode];
    }
    
    public void update(int i, int val) {
        int length = nums.length;
        update(nums,tree,0,0,length - 1,i,val);
    }

    private void update(int [] nums,int [] tree, int node, int start, int end,int i,int val) {
        if (start == end) {
            nums[i] = val;
            tree[node] = val;
            return;
        }
        int mid = (start + end) / 2;
        int leftNode = 2 * node + 1;
        int rightNode = 2 * node + 2;
        if (i >= start && i <= mid) {
            update(nums,tree,leftNode,start,mid,i,val);
        }else {
            update(nums,tree,rightNode,mid + 1, end, i,val);
        }
        tree[node] = tree[leftNode] + tree[rightNode];
    }
    
    public int sumRange(int i, int j) {
        int length = nums.length;
        return query(nums,tree,0,0,length - 1,i,j);
    }

    public int query(int [] nums, int [] tree, int node, int start, int end,int i,int j) {
        if (i > end || j < start) {
            return 0;
        }else if (i <= start && j >= end) {
            return tree[node];
        }else if (start == end) {
            return tree[node];
        }
        int mid = (start + end) / 2;
        int leftNode = 2 * node + 1;
        int rightNode = 2 * node + 2;
        return query(nums,tree,leftNode,start,mid,i,j) + query(nums,tree,rightNode,mid+1,end,i,j);
    }
}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */
```