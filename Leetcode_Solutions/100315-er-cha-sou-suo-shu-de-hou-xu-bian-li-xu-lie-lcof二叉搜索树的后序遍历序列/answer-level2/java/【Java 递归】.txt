1. 判断一个序列是否为二叉搜索树的后续遍历，正常的逻辑是先拿最后一个值作为根节点，然后寻找左右子树。
2. 因为二叉搜索树的特性，`左子树上所有结点的值小于根节点的值，右子树上所有结点的值大于根节点的值`， 以`[1,6,3,2,5]`为例，5为根节点，那么6之前的[1]只能是左子树,[6,2,3]是右子树。因为右子树中包含小于5的2和3，所以右子树不满足条件。如果左右子树均满足条件，那么再判断左右子树序列能否构成二叉搜索树的后续遍历
3. 递归终止的条件是某个树的序列长度为1或者2，因为对于[1,2]或者[2,1]都是可以成为一棵二叉搜索树的后续遍历序列的

```
class Solution {
    public boolean verifyPostorder(int[] postorder) {
        return helper(postorder, 0, postorder.length-1);
    }

    private boolean helper(int[] postorder, int start, int end){
        if(end-start<2) return true;
        int rootVal = postorder[end];

        // 分割左右子树
        int leftEnd=end-1, rightStart=end;
        for(int i=start; i<=end; i++){
            if(postorder[i]>rootVal){
                rightStart=i;
                leftEnd=i-1;
                break;
            }
        }

        // 判断左右子树结点的值是否满足二叉搜索树的条件
        for(int i=start; i<=leftEnd; i++){
            if(postorder[i] > rootVal){
                return false;
            }
        }
        for(int i=rightStart; i<=end-1; i++){
            if(postorder[i] < rootVal){
                return false;
            }
        }
        return helper(postorder, start, leftEnd) && helper(postorder, rightStart, end-1);
    }
}
```
