```java
class Solution {
   public static Node construct(int[][] grid) {
        return construct(grid, 0, grid.length, 0, grid.length);
    }

    public static Node construct(int[][] grid, int top, int bottom, int left, int right) {
        // 单元格内只有一个元素
        if (top == bottom - 1 &&  left == right - 1) {
            return new Node(grid[top][left] == 1, true);
        }

        Node topLeft = construct(grid, top, (top + bottom) / 2, left, (right + left) / 2);
        Node topRight = construct(grid, top, (top + bottom) / 2, (right + left) / 2, right);
        Node bottomLeft = construct(grid, (top + bottom) / 2, bottom, left, (right + left) / 2);
        Node bottomRight = construct(grid, (top + bottom) / 2, bottom, (right + left) / 2, right);
        // 是叶子节点 并且 值相同
        if (topLeft.isLeaf && bottomLeft.isLeaf && topRight.isLeaf && bottomRight.isLeaf) {
            if (topLeft.val == topRight.val && topLeft.val == bottomLeft.val &&topLeft.val == bottomRight.val) {
                // 合并
                return new Node(topLeft.val,true);
            }
        }
        return new Node(false,false,topLeft,topRight,bottomLeft,bottomRight);
    }
}
```
