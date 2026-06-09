### 解题思路


### 代码

```java
class Solution {
    
    public class Pair<E>{
        public E value;
        public int index;

        public Pair(E value, int index) {
            this.value = value;
            this.index = index;
        }
    }
    
    public class SegmentTreeNode {
        public int l;
        public int r;
        public Pair<Integer> value;
        public SegmentTreeNode left;
        public SegmentTreeNode right;

        public SegmentTreeNode(int l, int r) {
            this.l = l;
            this.r = r;
        }

        public SegmentTreeNode(int l, int r, Pair value) {
            this.l = l;
            this.r = r;
            this.value = value;
        }
    }
    
    public class SegmentTree {
        public int[] nums;
        public SegmentTreeNode root;

        public BiFunction<Pair<Integer>,Pair<Integer>,Pair<Integer>> func;

        public SegmentTree(int[] nums, BiFunction<Pair<Integer>, Pair<Integer>, Pair<Integer>> func) {
            if(nums.length == 0){
                throw new RuntimeException("构造数组不能为空!");
            }
            this.nums = nums;
            this.func = func;
            this.root = build(0, nums.length-1);
        }

        private SegmentTreeNode build(int l, int r){
            if(l == r){
                return new SegmentTreeNode(l, r, new Pair(this.nums[l], l));
            }
            if(l > r){
                return null;
            }
            int mid = (l + r) / 2;
            SegmentTreeNode cur = new SegmentTreeNode(l, r);
            cur.left = build(l, mid);
            cur.right = build(mid+1, r);
            cur.value = this.func.apply(cur.left.value, cur.right.value);
            return cur;
        }

        public Pair<Integer> search(int i, int j){
            if(i < 0 || j >= this.nums.length || i > j){
                throw new RuntimeException("区间不合法");
            }
            return _search(this.root, i, j);
        }

        private Pair<Integer> _search(SegmentTreeNode node, int l, int r){
            if(node.l == l && node.r == r){
                return node.value;
            }
            int mid = (node.l + node.r) / 2;

            if(r <= mid){
                return _search(node.left, l, r);
            }
            else if(l > mid){
                return _search(node.right, l, r);
            }
            return this.func.apply(_search(node.left, l, mid), _search(node.right, mid+1, r));
        }

    }
    
    private int helper(int i, int j, int[] heights, SegmentTree st){
        if(i > j){
            return 0;
        }
        else if(i == j){
            return heights[i];
        }
        else{
            Pair<Integer> minRect = st.search(i, j);
            int minHeight = minRect.value, minIndex = minRect.index;
            return Math.max(minHeight*(j - i + 1), Math.max(helper(i, minIndex-1, heights, st), helper(minIndex+1, j, heights, st)));
        }
    }

    public int largestRectangleArea(int[] heights) {
        if(heights == null || heights.length == 0){
            return 0;
        }
        SegmentTree st = new SegmentTree(heights, (a, b) -> a.value <= b.value ? a : b);
        return helper(0, heights.length-1, heights, st);
    }

}
```