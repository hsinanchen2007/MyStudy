### 解题思路
线段树是一种查询和更新都是O(logN)级别的数据结构，可以用于解决多种范围查询问题，比如在对数时间内从数组中找到最小值、最大值、总和、最大公约数、最小公倍数等。

使用线段树的前提是，结果集要满足区级加法，也就是最后的结果要等于左区间的解+右区间的解。

本人线段树也是刚刚入门，文字性东西说不出来太多，直接上代码了。以后再回来更新

### 代码

```java
class NumArray {

    private SegmentTree root;

    /**
     * 线段树结构体类
     */
    private static class SegmentTree {
        int start;// 节点线段的开始下标
        int end;// 节点线段的结束下标
        int sumValue;// 节点线段开始-结束所有值的和，start==end的时候，就是节点本身的值

        SegmentTree left;// 左孩子
        SegmentTree right;// 右孩子
        SegmentTree parent;// 父亲指针

        SegmentTree(int start,int end){
            this(start,end,0);
        }

        SegmentTree(int start,int end,int sumValue){
            this.start = start;
            this.end = end;
            this.sumValue = sumValue;
        }
    }

    public NumArray(int[] nums) {
        this.root = buildSegmentTree(nums,0,nums.length - 1);
    }

    /**
     * 构造线段树
     * @param nums nums
     * @param start 线段开始位置
     * @param end 线段结束位置
     * @return 线段树节点
     */
    private SegmentTree buildSegmentTree(int[] nums,int start,int end){
        if (start > end){
            return null;
        }else if(start == end){
            // 节点只有一个值了
            return new SegmentTree(start,end,nums[start]);
        }
        int mid = start + (end - start >> 1);// 取得中间节点
        // 递归构造左孩子
        SegmentTree left = buildSegmentTree(nums,start,mid);
        // 递归构造右孩子
        SegmentTree right = buildSegmentTree(nums,mid + 1,end);
        // 当前节点
        SegmentTree curRoot = new SegmentTree(start,end);
        // 当前节点的值，等于左右节点之和
        if (left != null){
            curRoot.left = left;
            left.parent = curRoot;
            curRoot.sumValue += left.sumValue;
        }
        if (right != null){
            curRoot.sumValue += right.sumValue;
            right.parent = curRoot;
            curRoot.right = right;
        }
        return curRoot;
    }

    public void update(int i, int val) {
        if (i < this.root.start || i > this.root.end){
            return;
        }
        SegmentTree node = this.root;
        // 想等就是当前节点
        while (node.start != node.end){
            int  mid = node.start + (node.end - node.start >> 1);
            if (mid >= i){
                // 左偏移
                node = node.left;
            }else {
                // 右偏移
                node = node.right;
            }
        }
        // 节点替换
        node.sumValue = val;
        // 递推更新父节点
        while (node.parent != null){
            node.parent.sumValue = node.parent.left.sumValue + node.parent.right.sumValue;
            node = node.parent;
        }
    }

    public int sumRange(int i, int j) {
        return sumNode(root,i,j);
    }

    private int sumNode(SegmentTree root,int i,int j){
        if(root.end == j && root.start == i){
            return root.sumValue;
        }else{
            int mid = root.start + (root.end-root.start >> 1);
            if(mid >= j){
                return sumNode(root.left,i,j);
            }else if(mid<i){
                return sumNode(root.right,i,j);
            }else{
                return sumNode(root.left,i,mid)+sumNode(root.right,mid+1,j);
            }
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