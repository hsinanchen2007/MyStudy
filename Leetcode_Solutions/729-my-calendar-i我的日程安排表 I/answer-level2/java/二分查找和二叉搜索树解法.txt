# 解法一：二分查找
```java

/**
 * @author li
 * @version 1.0
 * @date 2019-09-30 14:40
 **/
public class MyCalendar {
    private List<int[]> list;

    public MyCalendar() {
        list = new ArrayList<>();
    }

    public boolean book(int start, int end) {
        int[] toInsert = new int[]{start, end};
        if (list.size() <= 0) {
            list.add(toInsert);
            return true;
        }
        // 二分查找插入位置
        int index = Collections.binarySearch(list, toInsert, Comparator.comparingInt(o -> o[0]));
        if (index < 0) {
            index = -index - 1;
            if (index == 0) {
                // 插到首部
                if (end <= list.get(0)[0]) {
                    list.add(0, toInsert);
                    return true;
                }
            } else if (index == list.size()) {
                // 插到末尾
                if (start >= list.get(index - 1)[1]) {
                    list.add(toInsert);
                    return true;
                }
            } else if (start >= list.get(index - 1)[1] && end <= list.get(index)[0]) {
                // 插到中间
                list.add(index, toInsert);
                return true;
            }
        }
        return false;
    }
}
```

# 解法二：二叉搜索树
```java
class MyCalendar {
    static class BstNode {
        int start;
        int end;
        BstNode left;
        BstNode right;

        public BstNode(int start, int end) {
            this.start = start;
            this.end = end;
        }
    }

    private BstNode root;

    public MyCalendar() {
    }

    public boolean book(int start, int end) {
        if (root == null) {
            root = new BstNode(start, end);
            return true;
        }
        BstNode node = root;
        while (true) {
            if (end <= node.start) {
                if (node.left == null) {
                    node.left = new BstNode(start, end);
                    return true;
                } else {
                    node = node.left;
                }
            } else if (start >= node.end) {
                if (node.right == null) {
                    node.right = new BstNode(start, end);
                    return true;
                } else {
                    node = node.right;
                }
            } else {
                return false;
            }
        }
    }

}
```
