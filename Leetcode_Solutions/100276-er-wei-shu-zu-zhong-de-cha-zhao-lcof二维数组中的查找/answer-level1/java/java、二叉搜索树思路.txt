![image.png](https://pic.leetcode-cn.com/b6ba03d8c97705bd1010c30b21378d53cae20ed28a468557b9059e84c6626df4-image.png)


引用了评论区大神的二叉搜索树的思路。

以右上角为根，左方向为左节点，下方向为右节点，如果找到了则直接返回true，如果要找的值小于根，则递归到"左"孩子处；如果要找的值大于根，则递归到"右"孩子处。

越界则直接返回。


```java
class Solution {
    public boolean findNumberIn2DArray(int[][] matrix, int target) {
        int r = matrix.length;
        if (r == 0) return false;
        int c = matrix[0].length;
        if (c == 0) return false;
        
        return search(matrix, target, 0, c - 1, r, c);        
    }
    
    public boolean search(int[][] arr, int n, int i, int j, int r, int c) {
        if (i >= r || j < 0) return false;
        int root = arr[i][j];
        if (root == n) return true;
        if (n > root) {
            return search(arr, n, i + 1, j, r, c);
        } else {
            return search(arr, n, i, j - 1, r, c);
        }
    }
}
```