利用层次遍历序列化。需要注意的是只有当遍历到最后一层时，不再将null节点序列化。
```
代码块
public class Codec {
    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
        if(root == null){
            return "null";
        }
        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);
        StringBuilder sb = new StringBuilder();
        int depth = getDepth(root);
        int n = 0;
        while(!q.isEmpty()){
            int size = q.size();
            n++;
            for(int i = 0; i < size; i++){
                TreeNode tmp = q.poll();
                if(tmp == null){
                    sb.append("null").append(",");
                }else{
                    sb.append(tmp.val).append(",");
                    if(tmp.left != null){
                        q.add(tmp.left);
                    }else if(n != depth){
                        q.add(null);
                    }
                    if(tmp.right!=null){
                        q.add(tmp.right);
                    }else if(n != depth){
                        q.add(null);
                    }
                }
            }
        }

        return sb.toString();
    }

    private int getDepth(TreeNode root) {
        if(root == null){
            return 0;
        }
        return Math.max(getDepth(root.left),getDepth(root.right))+1;
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        String[] strs = data.split(",");
        TreeNode[] tds = new TreeNode[strs.length];
        for(int i = 0; i < strs.length; i++){
            if(!strs[i].equals("null")){
                tds[i] = new TreeNode(Integer.parseInt(strs[i]));
            }
        }
        int cur = 1;
        for(int i = 0; i < strs.length; i++){
            if(tds[i] != null && cur < strs.length){
                tds[i].left = tds[cur++];
                tds[i].right = tds[cur++];
            }
        }
        return tds[0];
    }
}
```
