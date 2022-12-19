### 解题思路
此处撰写解题思路
根据二叉搜索树种左子树所有节点的值都小于根节点的值,右子树的所有节点的值都大于根节点递归找值
### 代码

```java
class Solution {
    public boolean verifyPostorder(int[] postorder) {
        Boolean ans = new Boolean(true);
        if (postorder == null || postorder.length == 0) {
            return ans;
        }
        ans = verifyPostorderHelper(postorder, 0, postorder.length - 1);
        return ans;
    }

    private boolean verifyPostorderHelper(int[] postOrder, int start, int end) {
        if (start >= end) {
            return true;
        }
        int root = postOrder[end];
        int index = end;
        boolean flag = true;
        //找到左子树和右子树
        while (index > start) {
            --index;
            if (postOrder[index] < root) {
                flag = false;
                break;
            }
        }
        //验证左右子树是否满足二叉搜索树中值的大小关系,即左子树的所有值都小于根节点,素有右子树都大于根节点
        if(!flag){//没有左子树则不判断
            for (int i = start; i <= index; i++) {
                if (postOrder[i] > root) {
                    return false;
                }
            }
        }
        for (int i = index + 1; i <= end; i++) {
            if (postOrder[i] < root) {
                return false;
            }
        }
        return verifyPostorderHelper(postOrder,start,index) && verifyPostorderHelper(postOrder,index +1,end - 1);
    }
}
```