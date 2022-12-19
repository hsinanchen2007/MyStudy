### 解题思路
此处撰写解题思路
二叉搜索树左子树小于根节点，右子树大于根节点，后序序列最后一个节点为根节点。
递归方法定义：根节点的满足条件的左右子树的数量和应该等于本层要求的数量和，
### 代码

```java
class Solution {
    //左、右、根，又是BST，所以左边<根，右边>根
    private int i=0;
    private int[] postorder;
    public boolean verifyPostorder(int[] postorder) {
        if(postorder.length==0){
            return true;
        }
        this.postorder = postorder;
        return isLegal(0,postorder.length-1);
    }
    public boolean isLegal(int start,int rootIndex){
        int leftStart = start;
        if(start >= rootIndex){
            return true;
        }
        //本层验证左子树+右子树的数量和符合要求
        //左子树
        while(start<rootIndex && postorder[start]<postorder[rootIndex]){
            start++;
        }
        int leftRootIndex = start-1;
        int rightStart = start;
        //右子树可能会溢出
        while(start<rootIndex && postorder[start]>postorder[rootIndex]){
            start++;
        }
        //判断左右子树数量和是否等于目标数量和        
        if(start != rootIndex){
            return false;
        }
        int rightRootInex = start-1;
        return isLegal(leftStart, leftRootIndex) && isLegal(rightStart, rightRootInex);
    }
}
```