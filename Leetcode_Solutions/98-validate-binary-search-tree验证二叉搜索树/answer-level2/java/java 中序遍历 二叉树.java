### 解题思路
中序遍历二叉树的过程中判断当前元素是否大于上一个元素
如果是，则继续遍历
如果否，则结束遍历，返回 false;
如果整个二叉树都遍历完了，则返回 true;

### 代码

```java
class Solution {
    private List<Integer> elementList = new ArrayList<>();
    private boolean isValid = true;
    public void traverseBTree(TreeNode root){
        if(root!=null&&isValid){
            if(root.left!=null) traverseBTree(root.left);
            if(!elementList.isEmpty()&&root.val<=elementList.get(elementList.size()-1))
                isValid = false;
            else
                elementList.add(root.val);
            if(root.right!=null)  traverseBTree(root.right);
        }
    }
    public boolean isValidBST(TreeNode root) {
        elementList.clear();
        isValid = true;
        traverseBTree(root);
        return isValid;
    }
}
```