### 解题思路
1. 使用队列辅助做层次遍历的方法解决问题。序列化时，使用StringBuilder.append的方式拼接字符串比String直接相加的方式快很多。
2. 因为String拼接字符串会频繁开辟新内存，速度变慢。

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
        Queue<TreeNode> queue = new LinkedList<>();
        queue.offer(root);
        StringBuilder sb = new StringBuilder();
        while(!queue.isEmpty()){
            TreeNode treenode = queue.poll();
            if(treenode != null){
                queue.offer(treenode.left);
                queue.offer(treenode.right);
                sb.append(treenode.val);
                sb.append("#");
            }
            else sb.append("null#");
        }
        return sb.toString();
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        Queue<TreeNode> queue = new LinkedList<>();
        Queue<TreeNode> queue2 = new LinkedList<>();
        char[] dataArray = data.toCharArray();
        for(int i = 0, start = 0; i < dataArray.length; i++){
            if(dataArray[i] == '#'){
                String pre = data.substring(start, i);
                if(pre.equals("null")) queue.offer(null);
                else queue.offer(new TreeNode(Integer.parseInt(pre)));
                start = i + 1;
            }
        }
        TreeNode root = queue.poll();
        queue2.offer(root);
        while(!queue.isEmpty() && !queue2.isEmpty() ){
            TreeNode cur = queue2.poll();
            cur.left = queue.peek();
            if(queue.peek() != null) queue2.offer(queue.peek());
            queue.poll();
            cur.right = queue.peek();
            if(queue.peek() != null) queue2.offer(queue.peek());
            queue.poll();
        }
        return root;
    }
}

// Your Codec object will be instantiated and called as such:
// Codec codec = new Codec();
// codec.deserialize(codec.serialize(root));
```