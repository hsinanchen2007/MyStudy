**写个中序遍历 树中的元素存到一个list中 遍历一下list判断元素是否有序 其它的什么一行两行代码的老夫实在是脑子不够**
```
class Solution {
    public boolean isValidBST(TreeNode root) {
        
        List<Integer> list = new ArrayList<>();
        
        inOrder(root, list);
        
        for (int i=1; i<list.size(); i++) {
            if (list.get(i) <= list.get(i-1))
                return false;
        }
        
        return true;
    }
    
    private void inOrder(TreeNode node, List<Integer> list) {
        
        if (node == null)
            return;
        
        inOrder(node.left, list);
        list.add(node.val);
        inOrder(node.right, list);
    }
}
```
