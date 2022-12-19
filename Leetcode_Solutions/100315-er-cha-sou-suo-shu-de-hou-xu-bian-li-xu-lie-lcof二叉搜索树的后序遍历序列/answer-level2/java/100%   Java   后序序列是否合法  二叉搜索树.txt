### 解题思路
递归处理：后序的特点，最右边为根，前面的序列均小于最右边，之后数据均大于最右！！！！

### 代码

```java
class Solution {
    public boolean verifyPostorder(int[] postorder) {
        if (postorder == null || postorder.length == 0) {
            return true;
        }
        
        return func(postorder, 0, postorder.length - 1);
    }

    private boolean func(int[] postorder, int left, int right) {
        if (left >= right) {
            return true;
        }

        int i = left;
        // 从left遍历，找到大于right的停止，小于right的数据为左子树节点
        while (i < right && postorder[i] < postorder[right]) {
            i++;
        }
        int j = i;
        // 继续遍历剩余序列，如果存在小于right的则此序列不是一颗二叉搜索树的序列，返回false
        while (j < right) {
            if (postorder[j] < postorder[right]) {
                return false;
            }
            j++;
        }

        // 递归处理左子树和右子树，right为根，不再参与递归
        return func(postorder, left, i - 1) && func(postorder, i, right - 1);
    }
}
```