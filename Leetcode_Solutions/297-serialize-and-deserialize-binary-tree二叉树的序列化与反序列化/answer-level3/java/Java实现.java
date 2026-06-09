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
        return serializeHelper(root).toString();
    }
    public StringBuilder serializeHelper(TreeNode node)
    {
        if(node==null)
        return new StringBuilder("#!");
        StringBuilder sb=new StringBuilder();
        sb.append(node.val);
        sb.append("!");
        sb.append(serializeHelper(node.left));
        sb.append(serializeHelper(node.right));
        return sb;
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        String[] array=data.split("!");
        Queue<String> queue=new LinkedList<>();
        for(int i=0;i<array.length;i++)
        {
            queue.offer(array[i]);
        }
         return deserialize(queue);
    }

     public TreeNode deserialize(Queue<String> queue) {
       String s=queue.poll();
       if(s.equals("#"))
       {
           return null;
       }
       TreeNode node=new TreeNode(Integer.parseInt(s));
       node.left=deserialize(queue);
       node.right=deserialize(queue);
       return node;
    }
}

// Your Codec object will be instantiated and called as such:
// Codec codec = new Codec();
// codec.deserialize(codec.serialize(root));
```