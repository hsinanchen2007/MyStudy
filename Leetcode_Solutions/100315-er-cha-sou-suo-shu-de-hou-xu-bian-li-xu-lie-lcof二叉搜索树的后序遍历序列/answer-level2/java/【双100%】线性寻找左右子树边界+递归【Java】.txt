### 解题思路

当lens = 0 时， 树为空，满足二叉搜索树的条件。
当lens = 1 时，树只有一个根节点，满足二叉搜索树的条件。
当lens = 2 时，postorder[1] 为根节点，
  如果 postorder[0] > postorder[1], postorder[0]为右孩子时满足二叉搜索树条件。
  如果 postorder[0] < postorder[1], postorder[0]为左孩子时满足二叉搜索树条件。
综述可知，lens <= 2时，postorder数组一定满足二叉搜索树的后序遍历结果。
当lens >= 3 时，寻找一个临界，临界左边元素为根节点postorder[lens-1]的左子树，临界右边的元素(除根节点以外)是根节点的右子树。
注意：左子树和右子树都可以为空。
分析可知，这个临界可能不存在，如果存在有且只有一个。
如果存在边界，递归判断左子树和右子树是否都是满足二叉搜索树的后序遍历结果。
如果满足则整棵树都满足，不然则没有满足的二叉搜索树树存在。
### 代码

```java
class Solution {
    public boolean verifyPostorder(int[] postorder) {
        int lens = postorder.length;
        if(lens <= 2 ) return true;
        if(lens >= 3){
            int left = -1;
            int right = lens-1;
            for(int i=0; i < lens-1; i++){
                if(postorder[i] < postorder[lens-1]) left = i;
                else break;
            }
            for(int i=lens-2; i >= 0; i--){
                if(postorder[i] > postorder[lens-1]) right = i;
                else break;
            }
            //System.out.println("left = " + left + " right = "+ right);
            //边界存在条件：right - left == 1
            if(right - left == 1){
                if(verifyPostorder(Arrays.copyOfRange(postorder, 0, left+1)) && verifyPostorder(Arrays.copyOfRange(postorder, left+1, lens-1))) return true;
            }
        }
        return false;
    }
    
}
```