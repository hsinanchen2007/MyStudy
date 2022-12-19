### 解题思路
此处撰写解题思路

### 代码

```java
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
public class Codec {

    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
        return reserialize(root,"");
    }
    public String reserialize(TreeNode root,String str){
        if(root == null) {
            str += "null,";
        }else{
            str = reserialize(root.left,str);
            str = reserialize(root.right,str);
            str += String.valueOf(root.val) + ",";
        }
        return str;    

    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        String[] datas = data.split(",");
        List<String> list = new LinkedList<>(Arrays.asList(datas));
        return rdeserialize(list);
    }
    public TreeNode rdeserialize(List<String> list){
        if(list.get(list.size() - 1).equals("null")){
            list.remove(list.size() - 1);
            return null;
        }
        TreeNode root = new TreeNode(Integer.valueOf(list.get(list.size()-1)));
        list.remove(list.size()-1);
        root.right = rdeserialize(list);
        root.left = rdeserialize(list);
        return root;
    }
}

// Your Codec object will be instantiated and called as such:
// Codec codec = new Codec();
// codec.deserialize(codec.serialize(root));
```