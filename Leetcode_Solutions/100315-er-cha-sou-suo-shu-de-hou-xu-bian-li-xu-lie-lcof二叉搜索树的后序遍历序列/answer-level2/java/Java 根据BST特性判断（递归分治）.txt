### 解题思路
BST后序遍历，从尾部找根。
找到根之后，以根的值为界，将其余部分分成左子树和右子树，
若左右子树不合法return false；合法则将子树递归计算是否合法

当子树只剩一个值，或为空时，return true;

### 代码

```java
class Solution {
    public boolean verifyPostorder(int[] postorder) {
        int length = postorder.length;
        List<Integer> tree = new ArrayList();
        for(int i=0; i<length; i++)
            tree.add(postorder[i]);
        return isBST(tree);
    }
    
    public boolean isBST(List<Integer> tree)
    {
        if(tree.size() == 0 || tree.size() == 1)
            return true;
        
        int root = tree.get(tree.size()-1);
        tree.remove(tree.size()-1);
        
        List<Integer> leftTree = new ArrayList();
        List<Integer> rightTree = new ArrayList();
        boolean startRight = false;
        boolean res = true;
        
        for(int i=0; i<tree.size(); i++)
        {
            if(tree.get(i) < root)
            {
                leftTree.add(tree.get(i));
                if(startRight)  res = false;
            }
            else
            {
                startRight = true;
                rightTree.add(tree.get(i));
            }
        }
        
        if(!res)    return res;
        else    
            return isBST(leftTree) && isBST(rightTree);
    }
}
```