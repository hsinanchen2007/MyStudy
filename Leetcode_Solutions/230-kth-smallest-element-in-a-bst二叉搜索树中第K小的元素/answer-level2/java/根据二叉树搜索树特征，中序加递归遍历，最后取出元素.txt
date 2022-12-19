
- 根据二叉树搜索树特征，中序加递归遍历，最后取出元素
```
class Solution {
    public int kthSmallest(TreeNode root, int k) {
        List<Integer> list = new ArrayList<>();
        inorder(root,list);
        return list.get(k-1);
    }

    public void inorder(TreeNode node ,List list){
         if(node !=null){
             inorder(node.left,list);
             list.add(node.val);
             inorder(node.right,list);
         }
        

    }
}

```