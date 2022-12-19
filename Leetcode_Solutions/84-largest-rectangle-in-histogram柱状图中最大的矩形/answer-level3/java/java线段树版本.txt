看到官方题解用线段树优化，只有c++版本，其他评论也没有java线段树，就用java誊写了一遍。
试了一下效果拔群。上面是用线段树，下面时间是没用线段树（每次循环找最小值）的。
![image.png](https://pic.leetcode-cn.com/8207c4067278db353786df8644e5c02c2b3923b6eaa887ac204e251dbddb05c1-image.png)

这是官方发的c++版的线段树[https://leetcode.com/problems/largest-rectangle-in-histogram/discuss/28941/segment-tree-solution-just-another-idea-onlogn-solution]()
```
class SegTreeNode {
    int start;
    int end;
    int min;
    SegTreeNode left;
    SegTreeNode right;
    SegTreeNode(int start, int end){
        this.start = start;
        this.end = end;
    }
}
class Solution {
    public int largestRectangleArea(int[] heights) {
        SegTreeNode root = buildSegmentTree(heights,0,heights.length-1);
        return largestRectangleArea(heights,root,0,heights.length-1);
    }

    public int largestRectangleArea(int[] heights,SegTreeNode root,int start,int end) {
        if(end<start)return 0;
        if(end==start)return heights[start];
        int minIndex = query(root,heights,start,end);
        int min = heights[minIndex];
        int ans = Math.max(largestRectangleArea(heights,root,start,minIndex-1),largestRectangleArea(heights,root,minIndex+1,end));
        return Math.max(ans,min*(end-start+1));
    }

    public SegTreeNode buildSegmentTree(int[] heights,int start, int end){
        if(start > end) return null;
        SegTreeNode root = new SegTreeNode(start,end);
        if(start == end){
            root.min = start;
        } else {
          int middle = (start + end) / 2;
          root.left = buildSegmentTree(heights,start,middle);
          root.right = buildSegmentTree(heights,middle+1,end);
          root.min = heights[root.right.min] < heights[root.left.min] ? root.right.min : root.left.min;
        }
        return root;
    }

    public int query(SegTreeNode root,int[] heights,int start,int end){
        if(root == null || end < root.start || start > root.end)return -1;
        if(start <= root.start && end >= root.end)return root.min;
        int leftMin = query(root.left,heights,start,end);
        int rightMin = query(root.right,heights,start,end);
        if(leftMin == -1) return rightMin;
        if(rightMin == -1) return leftMin;
        return heights[leftMin] < heights[rightMin] ? leftMin : rightMin;
    }
}
```
