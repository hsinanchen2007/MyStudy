    
    class Solution {
        // 线段树节点的定义
        class Node{
            int start;
            int end;
            int value;  //区间内的最小值
            int index;  //最小值的下标
            
            public Node(int start, int end) {
                this.start = start;
                this.end = end;
            }
        }
        
        // 线段树的定义
        class SegmentTree{
            int[] base;
            Node[] nodes;
            
            public SegmentTree(int[] heights) {
                base = new int[heights.length];
                for(int i = 0;i < base.length;i++) {
                    base[i] = heights[i];
                }
                nodes = new Node[4 * base.length];   // 需要4倍的空间，，
            }
            
            public void bulidtree(int index) {      //index 为选段数的第几个节点，因为节点存储在数组中
                Node temp = nodes[index];
                if(temp == null) {                  // 说明index为0，为线段树的根节点
                    nodes[index] = new Node(0, this.base.length - 1); 
                    temp = nodes[index];
                }
                
                if(temp.start == temp.end) {  //叶子节点
                    temp.index = temp.start;
                    temp.value = base[temp.start];
                }else {  //不是叶子节点先递归定下左右区间，即temp的左右孩子节点
                    int mid = (temp.start + temp.end) / 2;
                    nodes[2 * index + 1] = new Node(temp.start, mid);      // 注意不是  mid - 1
                    nodes[2 * index + 2] = new Node(mid + 1, temp.end);
                    bulidtree(2 * index + 1);
                    bulidtree(2 * index + 2);
                    if(nodes[2 * index + 1].value <= nodes[2 * index + 2].value) {
                        temp.value = nodes[2 * index + 1].value;
                        temp.index = nodes[2 * index + 1].index;
                    }else {
                        temp.value = nodes[2 * index + 2].value;
                        temp.index = nodes[2 * index + 2].index;
                    }
                }
            }
            
            public Node query(int index, int start, int end) {   // 入口index永远是0， 表示从树根往下查找
                Node temp = nodes[index];
                if(temp.start > end || temp.end < start) {       //没有交集
                    return null;
                }
                if(temp.start >= start && temp.end <= end) {     //当前区间被完全包含，返回
                    return temp;
                }
                // 下面是如果当前区间不完全包含，则继续切割区间
                Node left = query(2 * index + 1, start, end);    //注意这个是index ， 而不是temp.index
                long leftNum = left == null ? Long.MAX_VALUE : left.value;
                Node right = query(2 * index + 2, start, end);
                long rightNum = right == null ? Long.MAX_VALUE : right.value;
                return leftNum < rightNum ? left : right;
            }
        }

        public int largestRectangleArea(int[] heights) {
            if(heights.length == 0) {
                return 0;
            }
            SegmentTree st = new SegmentTree(heights);
            st.bulidtree(0);
            return dfs(heights, 0, heights.length - 1, st);
        }

        // 递归
        public int dfs(int[] heights, int left, int right, SegmentTree st) {
            if(left > right) {
                return 0;
            }
            Node min = st.query(0, left, right);
            int x = min.value * (right - left + 1);
            int y = dfs(heights, left, min.index - 1, st);
            int z = dfs(heights, min.index + 1, right, st);
            return Math.max(Math.max(x, y), z);
        }
    }