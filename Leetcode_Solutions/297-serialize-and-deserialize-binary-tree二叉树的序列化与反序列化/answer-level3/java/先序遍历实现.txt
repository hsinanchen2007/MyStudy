**序列化转换为String保存与反序列化重建回二叉树均借助于二叉树的先序遍历顺序**
```
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
    //以"!"作为各个节点值的分割符号，以"#"作为空值标记
    //直接先序遍历顺序累加各个节点值转换为String类型
    public String serialize(TreeNode root) {
        if(root==null){
            return "#!";
        }
        String str=root.val+"!";
        str+=serialize(root.left);
        str+=serialize(root.right);
        return str;
    }
    //将存储好的String类型数据去掉分割符号
    //将此时数据二叉树的先序遍历结果依次压入队列
    public TreeNode deserialize(String data) {
        String []arr=data.split("!");
        Queue <String> queue=new LinkedList<String>();
        for(int i=0;i<arr.length;i++){
            queue.offer(arr[i]);
        }
        //调用先序遍历递归方法（改动后）依次重建二叉树
        return deserialize(queue);
    }
    //传入队列
    public TreeNode deserialize(Queue <String> queue){
        //依次弹出队列中的节点值
        String str=queue.poll();
        //如果是"#",代表节点值为空,返回null
        if(str.equals("#")){
            return null;
        }
        //若节点值不为空，将其由String转换回int
        //将其作为当前节点值新建当前节点
        TreeNode root=new TreeNode(Integer.parseInt(str));
        //递归调用连接当前节点的左右节点
        root.left=deserialize(queue);  
        root.right=deserialize(queue);
        //递归完成后返回当前节点
        return root;
