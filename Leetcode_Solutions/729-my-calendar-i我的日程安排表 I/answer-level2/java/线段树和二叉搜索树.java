### 解题思路一
1.构造线段树节点。
2.新添加的线段树节点，要么只能全在node.start往左，要么只能全在node.end往右。
3.左右子树如果不存在，这表示该区间不存在，可以插入，如果存在，则往其左右子树递推即可。
4.不满足条件的则表示与当前节点的区间发生了重叠，不能插入。

本题构造的线段树节点，以及线段树的更新操作，基本上就是二叉搜索树新增节点的变形，极端情况下，效率会从O(logN)退化到O(N)

### 代码

```java
class MyCalendar {

    // 线段树的根
    private SegmentTreeNode root;

    /**
     * 线段树结构体
     */
    private static class SegmentTreeNode {
        int start;// 时间开始区间
        int end;// 时间结束区间

        SegmentTreeNode left;// 区间左孩子
        SegmentTreeNode right;// 区间右孩子

        SegmentTreeNode(int start,int end){
            this.start = start;
            this.end = end;
        }
    }

    public MyCalendar() {
        root = new SegmentTreeNode(0,0);
    }

    public boolean book(int start, int end) {
        return updateSegment(root,start,end);
    }

    /**
     * 更新线段树节点
     * @param root 线段树节点
     * @param start 新插入的开始时间
     * @param end 新插入的结束时间
     * @return 是否合法
     */
    private boolean updateSegment(SegmentTreeNode root,int start,int end){
        // 新节点，要么只能全在node.start往左，要么只能全在node.end往右
        SegmentTreeNode node = root;
        while (true){
            // 因为start,end是前闭后开区间，所以end可以取等号
            if (end <= node.start){
                // 左子树为空，表示可以添加
                if (node.left == null){
                    node.left = new SegmentTreeNode(start,end);
                    return true;
                }
                // 进入左子树线段树
                node = node.left;
            }else if (start >= node.end){
                // 右子树为空，表示可以添加
                if (node.right == null){
                    node.right = new SegmentTreeNode(start, end);
                    return true;
                }
                // 进入右子树的线段树
                node = node.right;
            }else {
                // start或end在[node.start,node.end)中，产生了重复预定
                return false;
            }
        }
    }
}

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * boolean param_1 = obj.book(start,end);
 */
```

### 解题思路二
直接利用TreeMap，以start为key,end为value。

1.找到比start小的值，看其value是不是比start大，如果大于start，则表示重复，不能插入
2.找到比start大的值，看其本身是不是比end小，如果小于end，则表示重复，不能插入

### 代码

```java
class MyCalendar {
    // key->start ; value->end
    private TreeMap<Integer,Integer> tm;

    public MyCalendar() {
        tm = new TreeMap<>();
    }

    public boolean book(int start, int end) {
        if (start >= end){
            return false;
        }
        Integer low = tm.floorKey(start);
        if(low != null && tm.get(low) > start){
            return false;// 前节点考虑
        }
        Integer high = tm.ceilingKey(start);
        if (high != null && high < end){
            return false;// 后节点考虑
        }
        tm.put(start,end);
        return true;
    }
}
```
