```
class Solution {
    public List<String> binaryTreePaths(TreeNode root) {
        List <String> ans = new ArrayList();
        if(root == null) return ans;
        StringBuffer sb = new StringBuffer();
        findPaths(root, ans, sb);
        return ans;
    }
    void findPaths(TreeNode node, List <String> ans, StringBuffer sb){
        if(node == null) return;
        sb.append(node.val + " ");
        if(node.left == null && node.right == null){
            ans.add(new String (sb.toString().trim().replaceAll(" ", "->")));
        }
        findPaths(node.left, ans, sb);
        findPaths(node.right, ans, sb);
        String last = String.valueOf(node.val);
        int lastIndex = sb.lastIndexOf(last);
        sb.delete(lastIndex, sb.length());
    }
}
```
相当于回溯（？）最后删除最后一个元素那里感觉处理得不好