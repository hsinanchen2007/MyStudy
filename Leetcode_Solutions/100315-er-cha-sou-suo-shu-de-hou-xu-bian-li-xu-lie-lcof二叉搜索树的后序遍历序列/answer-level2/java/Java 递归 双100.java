### 解题思路
只要看清楚是二叉搜索树，了解后续遍历数组最后一个为根节点，即可求解。

### 代码

```java
class Solution {
    int[] postorder;
    public boolean verifyPostorder(int[] postorder) {
        int pLen = postorder.length;
        if (pLen < 3)
            return true;
        this.postorder = postorder;
        return isBinaryTree(0, pLen - 1);
    }

    public boolean isBinaryTree(int start, int end) {
        if (end - start < 2)
            return true;
        int root = postorder[end];
        int i = start;
        while (i < end) {
            if (postorder[i] > root)
                break;
            i ++;
        }
        int j = i;
        while (j < end) {
            if (postorder[j] < root)
                return false;
            j ++;
        }
        return isBinaryTree(start, i - 1) && isBinaryTree(i, end - 1);
    }
}
```