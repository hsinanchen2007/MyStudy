### 解题思路
//1.序列化
    1.1 层次遍历，null值也要添加。然后拼“[,]”
  2.反序列化
    2.1 去掉[]，用截取字符串操作
    2.2 按照“,”分割成s[]
    2.3 设置root结点以s[0]的值建立的节点
    2.4 设置遍历索引index = 1；
    2.5 循环的添加结点，与层次遍历一致，只不过终止条件变为index来控制
    2.6 注意：遍历过程中要对index实时判断，队列中为null的结点取出来要continue

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
        if(root == null) return "[]";
        Queue<TreeNode> queue = new LinkedList();
        queue.offer(root);
        StringBuilder sb = new StringBuilder();
        while(!queue.isEmpty()){
            TreeNode node = queue.poll();
            sb.append((node == null ? "null" : node.val) + "," );
            if(node != null){
                queue.offer(node.left);
                queue.offer(node.right);
            }
        }
        String s = sb.toString().substring(0,sb.toString().length() - 1);
        return "[" + s + "]";
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        if(data.length() == 2) return null;
        data = data.substring(1,data.length() - 1);
        String[] split = data.split(",");
        TreeNode root = new TreeNode(Integer.parseInt(split[0]));
        Queue<TreeNode> queue = new LinkedList();
        queue.offer(root);
        int index = 1;
        while(index!=split.length){
            TreeNode node = queue.poll();
            if(node == null) continue;
            if(!"null".equals(split[index])){
                node.left = new TreeNode(Integer.parseInt(split[index])); 
            }
            queue.offer(node.left);
            index ++;
            if(index == split.length) break;
            if(!"null".equals(split[index])){
               node.right = new TreeNode(Integer.parseInt(split[index])); 
            }
            queue.offer(node.right);
            index ++;
        }
        return root;
    }
}

// Your Codec object will be instantiated and called as such:
// Codec codec = new Codec();
// codec.deserialize(codec.serialize(root));
```