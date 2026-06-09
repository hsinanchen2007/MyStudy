```java
class Solution {
    List<Integer> list = new ArrayList<Integer>();
    List<String> res = new ArrayList<String>();
    public List<String> binaryTreePaths(TreeNode root) {
        helper(root);
        return res;
    }

    public void helper(TreeNode node){
        if(null == node){
            return;
        }
        list.add(node.val);
        if(null != node.left){
            helper(node.left);
        }
        if(null != node.right){
            helper(node.right);
        }
        if(null == node.left && null == node.right){
            print();
        }
        list.remove(list.size()-1);
    }

    public void print(){
        StringBuilder sb = new StringBuilder();
        for(int i=0; i<list.size()-1; i++){
            sb.append(list.get(i));
            sb.append("->");
        }
        sb.append(list.get(list.size()-1));
        res.add(sb.toString());
    }
}
```
